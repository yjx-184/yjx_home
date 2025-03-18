- [整理ELF的相关内容](#整理elf的相关内容)
  - [ELF 头部（Ehdr）](#elf-头部ehdr)
  - [程序头（Program Header，Phdr）](#程序头program-headerphdr)
  - [段表（Section Header, Shdr）](#段表section-header-shdr)
  - [字符串和符号表String and symbol tables](#字符串和符号表string-and-symbol-tables)
    - [st\_info](#st_info)
    - [宏定义](#宏定义)
  - [重定位表](#重定位表)
  - [字符串表](#字符串表)



# 整理ELF的相关内容
elf - 可执行与链接格式（ELF）文件的格式.  
头文件：```#include <elf.h>```  
* 头文件 <elf.h> 定义了 ELF 可执行二进制文件的格式。这些文件包括普通可执行文件、可重定位目标文件、核心转储文件和共享对象文件。
* 使用 ELF 文件格式的可执行文件由 ELF 头部组成，后跟程序头表或节头表，或两者兼有。ELF 头部始终位于文件的偏移量 0 处。程序头表和节头表的偏移量在 ELF 头部中定义。这两个表描述了文件的其余细节。
* 此头文件以 C 结构体的形式描述了上述头部，同时还包括动态段、重定位段和符号表的结构。  

## ELF 头部（Ehdr）
ELF 头部由 Elf32_Ehdr 或 Elf64_Ehdr 结构体描述：  
作用：描述 ELF 文件的基本信息，如类型、架构、入口地址等。  
```
typedef struct {
    unsigned char e_ident[EI_NIDENT]; /* ELF 识别信息 */
    uint16_t e_type;     /* 文件类型，如可执行文件、共享库 */
    uint16_t e_machine;  /* 运行架构，如 x86_64 */
    uint32_t e_version;  /* 版本信息 */
    Elf32_Addr e_entry;  /* 入口地址 */
    Elf32_Off  e_phoff;  /* 程序头表偏移 */
    Elf32_Off  e_shoff;  /* 段头表偏移 */
    uint32_t e_flags;    /* 特定架构标志 */
    uint16_t e_ehsize;   /* ELF 头部大小 */
    uint16_t e_phentsize; /* 每个程序头表项大小 */
    uint16_t e_phnum;    /* 程序头表项个数 */
    uint16_t e_shentsize; /* 每个段头表项大小 */
    uint16_t e_shnum;    /* 段头表项个数 */
    uint16_t e_shstrndx; /* 段名称字符串表索引 */
} Elf32_Ehdr;
```  


## 程序头（Program Header，Phdr）
可执行文件或共享对象文件的程序头表是一个结构体数组，每个条目描述一个段或其他系统用于准备程序执行的信息。对象文件的一个段包含一个或多个节。程序头仅适用于可执行文件和共享对象文件。文件的程序头大小由 ELF 头的 e_phentsize 和 e_phnum 成员指定。  

作用：描述 ELF 文件在内存中的映射，如代码段、数据段的位置等。
```
typedef struct {
    uint32_t p_type;    /* 段类型，如 PT_LOAD（可加载段） */
    Elf32_Off p_offset; /* 段在文件中的偏移 */
    Elf32_Addr p_vaddr; /* 段在内存中的虚拟地址 */
    Elf32_Addr p_paddr; /* 物理地址（通常用于嵌入式） */
    uint32_t p_filesz;  /* 段在文件中的大小 */
    uint32_t p_memsz;   /* 段在内存中的大小 */
    uint32_t p_flags;   /* 访问权限，如 R、W、X */
    uint32_t p_align;   /* 内存对齐 */
} Elf32_Phdr;
```  
主要区别在于 p_flags 成员在结构体中的位置不同.  

**p_type 该结构体的成员指示此数组元素描述的段的类型或如何解释该数组元素的信息。**
* PT_NULL 该数组元素未使用，其他成员的值是未定义的。这允许程序头有被忽略的条目。
* PT_LOAD 该数组元素指定一个可加载的段，由p_filesz和p_memsz描述。文件中的字节被映射到内存段的开始。如果段的内存大小p_memsz大于文件大小p_filesz，那么“额外”的字节被定义为0，并跟在段的初始化区域之后。文件大小不能大于内存大小。程序头表中的可加载段条目按p_vaddr成员排序，以升序排列。
* PT_DYNAMIC 该数组元素指定动态链接信息。
* PT_INTERP 该数组元素指定一个以null结尾的路径名的位置和大小，用于调用作为解释器。该段类型仅对可执行文件有意义（尽管它可能出现在共享对象中）。然而，它在文件中不得出现超过一次。如果存在，它必须位于任何可加载段条目之前。
* PT_NOTE 该数组元素指定注释（ElfN_Nhdr）的位置。
* PT_SHLIB 该段类型是保留的，但其语义未指定。包含此类型数组元素的程序不符合ABI。
* PT_PHDR 如果存在，该数组元素指定程序头表本身的位置和大小，既在文件中也在程序的内存映像中。此段类型在文件中不能出现超过一次。此外，只有当程序头表是程序内存映像的一部分时，它才可能出现。如果存在，它必须位于任何可加载段条目之前。
* PT_LOPROC, PT_HIPROC 范围[PT_LOPROC, PT_HIPROC]内的值保留用于处理器特定的语义。
* PT_GNU_STACK GNU扩展，Linux内核使用它通过p_flags成员中设置的标志来控制堆栈的状态。

## 段表（Section Header, Shdr）
文件的段表（Section Header Table）用于定位所有的段。它是 Elf32_Shdr 或 Elf64_Shdr 结构体的数组。ELF 头的 e_shoff 成员给出了段表的字节偏移量，e_shnum 表示段表中的条目数量，e_shentsize 表示每个条目的大小（字节）。  

节头表索引是该数组的下标。一些节头表索引是保留的：初始条目和SHN_LORESERVE与SHN_HIRESERVE之间的索引。初始条目用于ELF扩展中的e_phnum、e_shnum和e_shstrndx；在其他情况下，初始条目中的每个字段都设置为零。对象文件没有为这些特殊索引提供节：  
* SHN_UNDEF： 该值标记一个未定义、缺失、不相关或其他无意义的节引用。
* SHN_LORESERVE： 该值指定保留索引范围的下界。
* SHN_LOPROC, SHN_HIPROC： 在[SHN_LOPROC, SHN_HIPROC]范围内的值保留给处理器特定的语义。
* SHN_ABS： 该值指定对应引用的绝对值。例如，相对于节号SHN_ABS定义的符号具有绝对值，并且不受重定位的影响。
* SHN_COMMON： 相对于该节定义的符号是公共符号，例如FORTRAN COMMON或未分配的C外部变量。
* SHN_HIRESERVE： 该值指定保留索引范围的上界。系统保留SHN_LORESERVE和SHN_HIRESERVE之间（包括）的索引。节头表不包含这些保留索引的条目。

作用：描述 ELF 文件中的各个段，如 .text、.data、.bss 等。  
```
typedef struct {
    uint32_t sh_name;      /* 段名称（字符串表索引） */
    uint32_t sh_type;      /* 段类型，如 SHT_PROGBITS（程序段） */
    uint32_t sh_flags;     /* 段标志，如可读、可写、可执行 */
    Elf32_Addr sh_addr;    /* 段在内存中的地址 */
    Elf32_Off sh_offset;   /* 段在文件中的偏移 */
    uint32_t sh_size;      /* 段大小 */
    uint32_t sh_link;      /* 关联段索引（如符号表的字符串表） */
    uint32_t sh_info;      /* 额外信息（如重定位表关联符号表） */
    uint32_t sh_addralign; /* 段对齐要求 */
    uint32_t sh_entsize;   /* 如果是表结构（如符号表），表示每个条目的大小 */
} Elf32_Shdr;
```  
32 位和 64 位的段表结构没有本质区别。  

1. sh_type 该成员对节的内容和语义进行分类。
* SHT_SYMTAB：此节包含符号表。通常，SHT_SYMTAB 提供链接编辑符号，尽管它也可以用于动态链接。作为一个完整的符号表，它可能包含许多对于动态链接不必要的符号。一个目标文件还可以包含一个 SHT_DYNSYM 节。
* SHT_STRTAB：此节包含字符串表。一个目标文件可能包含多个字符串表节。
* SHT_NULL： 该值将节头标记为非活动状态。它没有关联的节。节头的其他成员值是未定义的。
* SHT_PROGBITS： 该节包含由程序定义的信息，格式和意义完全由程序确定。
* SHT_RELA： 该节包含带有显式加数的重定位条目，例如32位类对象文件的Elf32_Rela类型。一个对象可能有多个重定位节。
* SHT_HASH： 该节包含符号哈希表。参与动态链接的对象必须包含符号哈希表。一个对象文件只能有一个哈希表。
* SHT_DYNAMIC： 该节包含用于动态链接的信息。一个对象文件只能有一个动态节。
* SHT_NOTE： 该节包含注释（ElfN_Nhdr）。

2. sh_flags
* SHF_WRITE： 该节包含在进程执行期间应该是可写的数据。
* SHF_ALLOC： 该节在进程执行期间占用内存。一些控制节不会驻留在对象文件的内存映像中。这些节的此属性为关闭。
* SHF_EXECINSTR： 该节包含可执行的机器指令。
* SHF_MASKPROC： 该掩码中的所有位保留用于处理器特定的语义。

***
各种段包含程序和控制信息：  

.bss  
该段保存未初始化的数据，这些数据会贡献到程序的内存映像中。根据定义，系统在程序开始运行时会将这些数据初始化为零。该段属于类型 SHT_NOBITS，属性类型为 SHF_ALLOC 和 SHF_WRITE。

.comment  
该段保存版本控制信息。该段属于类型 SHT_PROGBITS，不使用属性类型。

.ctors  
该段保存初始化后的指向 C++ 构造函数的指针。该段属于类型 SHT_PROGBITS，属性类型为 SHF_ALLOC 和 SHF_WRITE。

.data  
该段保存初始化后的数据，这些数据会贡献到程序的内存映像中。该段属于类型 SHT_PROGBITS，属性类型为 SHF_ALLOC 和 SHF_WRITE。

.data1  
该段保存初始化后的数据，这些数据会贡献到程序的内存映像中。该段属于类型 SHT_PROGBITS，属性类型为 SHF_ALLOC 和 SHF_WRITE。

.debug  
该段保存用于符号调试的信息，内容未指定。该段属于类型 SHT_PROGBITS，不使用属性类型。

.dtors  
该段保存初始化后的指向 C++ 析构函数的指针。该段属于类型 SHT_PROGBITS，属性类型为 SHF_ALLOC 和 SHF_WRITE。

.dynamic  
该段保存动态链接信息。该段的属性将包括 SHF_ALLOC 位。是否设置 SHF_WRITE 位是处理器特定的。该段属于类型 SHT_DYNAMIC，见上文中的属性。

.dynstr  
该段保存动态链接所需的字符串，通常是表示与符号表条目相关的名称的字符串。该段属于类型 SHT_STRTAB，使用的属性类型为 SHF_ALLOC。

.dynsym  
该段保存动态链接符号表。该段属于类型 SHT_DYNSYM，使用的属性类型为 SHF_ALLOC。

.fini  
该段保存贡献给进程终止代码的可执行指令。当程序正常退出时，系统会安排执行该段中的代码。该段属于类型 SHT_PROGBITS，使用的属性类型为 SHF_ALLOC 和 SHF_EXECINSTR。

.gnu.version  
该段保存版本符号表，一个 ElfN_Half 元素的数组。该段属于类型 SHT_GNU_versym，使用的属性类型为 SHF_ALLOC。

.gnu.version_d  
该段保存版本符号定义，一个 ElfN_Verdef 结构的表。该段属于类型 SHT_GNU_verdef，使用的属性类型为 SHF_ALLOC。

.gnu.version_r  
该段保存所需的版本符号元素，一个 ElfN_Verneed 结构的表。该段属于类型 SHT_GNU_versym，使用的属性类型为 SHF_ALLOC。

.got  
该段保存全局偏移表。该段属于类型 SHT_PROGBITS，属性是处理器特定的。

.hash  
该段保存符号哈希表。该段属于类型 SHT_HASH，使用的属性类型为 SHF_ALLOC。

.init  
该段保存贡献给进程初始化代码的可执行指令。当程序开始运行时，系统会安排执行该段中的代码，随后调用主程序入口点。该段属于类型 SHT_PROGBITS，使用的属性类型为 SHF_ALLOC 和 SHF_EXECINSTR。

.interp  
该段保存程序解释器的路径名。如果文件有包含该段的可加载段，则该段的属性将包括 SHF_ALLOC 位。否则，该位将关闭。该段属于类型 SHT_PROGBITS。

.line  
该段保存符号调试的行号信息，描述程序源代码与机器码之间的对应关系。内容未指定。该段属于类型 SHT_PROGBITS，不使用属性类型。

.note  
该段保存各种注释。该段属于类型 SHT_NOTE，不使用属性类型。

.note.ABI-tag  
该段用于声明 ELF 映像的预期运行时 ABI，可能包括操作系统名称及其运行时版本。该段属于类型 SHT_NOTE，唯一使用的属性是 SHF_ALLOC。

.note.gnu.build-id  
该段用于保存唯一标识 ELF 映像内容的 ID。不同的文件如果有相同的构建 ID，则应该包含相同的可执行内容。见 GNU 链接器 (ld (1)) 的 --build-id 选项了解更多详细信息。该段属于类型 SHT_NOTE，唯一使用的属性是 SHF_ALLOC。

.note.GNU-stack  
该段在 Linux 对象文件中用于声明栈属性。该段属于类型 SHT_PROGBITS，唯一使用的属性是 SHF_EXECINSTR。该属性表明该对象文件需要可执行栈。

.note.openbsd.ident  
OpenBSD 本地可执行文件通常包含该段，用于标识自身，以便内核在加载文件时跳过任何兼容性 ELF 二进制模拟测试。

.plt  
该段保存过程链接表。该段属于类型 SHT_PROGBITS，属性是处理器特定的。

.relNAME  
该段保存重定位信息。如文件包含包含重定位的可加载段，则该段的属性将包括 SHF_ALLOC 位，否则该位将关闭。根据约定，“NAME”由该段适用的重定位段提供。例如，.text 的重定位段通常命名为 .rel.text。该段属于类型 SHT_REL。

.relaNAME  
该段保存重定位信息。如文件包含包含重定位的可加载段，则该段的属性将包括 SHF_ALLOC 位，否则该位将关闭。根据约定，“NAME”由该段适用的重定位段提供。例如，.text 的重定位段通常命名为 .rela.text。该段属于类型 SHT_RELA。

.rodata  
该段保存只读数据，通常贡献到进程映像中的非可写段。该段属于类型 SHT_PROGBITS，使用的属性是 SHF_ALLOC。

.rodata1  
该段保存只读数据，通常贡献到进程映像中的非可写段。该段属于类型 SHT_PROGBITS，使用的属性是 SHF_ALLOC。

.shstrtab  
该段保存段名。该段属于类型 SHT_STRTAB，不使用属性类型。

.strtab  
该段保存字符串，通常是表示与符号表条目相关的名称的字符串。如果文件包含符号字符串表的可加载段，则该段的属性将包括 SHF_ALLOC 位，否则该位将关闭。该段属于类型 SHT_STRTAB。

.symtab  
该段保存符号表。如果文件包含符号表的可加载段，则该段的属性将包括 SHF_ALLOC 位，否则该位将关闭。该段属于类型 SHT_SYMTAB。

.text  
该段保存程序的“文本”，即可执行指令。该段属于类型 SHT_PROGBITS，使用的属性类型为 SHF_ALLOC 和 SHF_EXECINSTR。

## 字符串和符号表String and symbol tables
字符串表（String Table）段存储以空字符（null-terminated）结尾的字符序列，通常称为字符串。目标文件使用这些字符串来表示符号和段的名称。字符串的引用是字符串表段中的索引。第一个字节（索引为 0）被定义为存储空字节（\0），同样，字符串表的最后一个字节也必须是空字节，以确保所有字符串都以空字符结尾。  

目标文件的符号表（Symbol Table）存储了用于定位和重定位程序符号定义及引用的信息。符号表索引是该数组的下标。  

作用：描述 ELF 文件中的符号（如变量、函数等）。
```
typedef struct {
    uint32_t st_name;  /* 符号名称（字符串表索引） */
    Elf32_Addr st_value; /* 符号值（地址或偏移） */
    uint32_t st_size;  /* 符号大小 */
    unsigned char st_info;  /* 符号类型（如函数、变量）和绑定信息 */
    unsigned char st_other; /* 额外信息（通常未使用） */
    uint16_t st_shndx; /* 关联的段索引 */
} Elf32_Sym;
```  
32 位和 64 位版本的符号表具有相同的成员，只是它们的顺序有所不同。  

### st_info

此成员指定符号的类型和绑定属性：

- **STT_NOTYPE**  
  符号的类型未定义。

- **STT_OBJECT**  
  符号与数据对象相关联。

- **STT_FUNC**  
  符号与函数或其他可执行代码相关联。

- **STT_SECTION**  
  符号与节相关联。此类型的符号表条目主要用于重定位，并且通常具有 STB_LOCAL 绑定。

- **STT_FILE**  
  按约定，符号的名称给出了与目标文件相关的源文件的名称。文件符号具有 STB_LOCAL 绑定，其节索引为 SHN_ABS，并且如果存在，它会位于文件的其他 STB_LOCAL 符号之前。

- **STT_LOPROC, STT_HIPROC**  
  范围 [STT_LOPROC, STT_HIPROC] 内的值保留用于处理器特定的语义。

- **STB_LOCAL**  
  本地符号在包含其定义的目标文件之外不可见。同名的本地符号可以存在于多个文件中而不会互相干扰。

- **STB_GLOBAL**  
  全局符号对所有被合并的目标文件可见。一个文件定义的全局符号可以满足另一个文件对该符号的未定义引用。

- **STB_WEAK**  
  弱符号类似于全局符号，但它们的定义具有较低的优先级。

- **STB_LOPROC, STB_HIPROC**  
  范围 [STB_LOPROC, STB_HIPROC] 内的值保留用于处理器特定的语义。

### 宏定义

以下是用于打包和解包绑定和类型字段的宏：

- **ELF32_ST_BIND(info), ELF64_ST_BIND(info)**  
  从 st_info 值中提取绑定。

- **ELF32_ST_TYPE(info), ELF64_ST_TYPE(info)**  
  从 st_info 值中提取类型。

- **ELF32_ST_INFO(bind, type), ELF64_ST_INFO(bind, type)**  
  将绑定和类型转换为 st_info 值。

## 重定位表 
作用：描述重定位信息，用于调整符号地址。  
```
typedef struct {
    Elf32_Addr r_offset; /* 需要重定位的地址 */
    uint32_t r_info;     /* 符号索引和重定位类型 */
} Elf32_Rel;

typedef struct {
    Elf32_Addr r_offset; /* 需要重定位的地址 */
    uint32_t r_info;     /* 符号索引和重定位类型 */
    int32_t r_addend;    /* 额外的修正值 */
} Elf32_Rela;
```  

## 字符串表 
作用：ELF 文件中的许多部分（如符号表、段头）使用字符串表来存储名称。  
结构体本身没有单独定义，但字符串表通常作为 .strtab 或 .shstrtab 段存储在 ELF 文件中。  
