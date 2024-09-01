set nu ai hls et ru ic is sc cul
set re=1 ts=4 sts=4 sw=4 ls=2 mouse=a
set timeoutlen=300
hi cursorline cterm=none
"Select region and type :Hash to hash your selection."
ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
map <F9> :w !clear && g++ -std=c++17 -Ddebug -O2 -Wall -lm -g % && ./a.out<CR>
