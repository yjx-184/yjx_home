#!/bin/bash
marco() {
	echo "p(pwd)" > $HOME/Mystudy/yjx_learn/Learn_Linux/marco_history.log
	echo "Save pwd $(pwd)"
}
polo() {
	cd "$(cat "$HOME/Mystudy/yjx_learn/Learn_Linux/marco_history.log")"
}
