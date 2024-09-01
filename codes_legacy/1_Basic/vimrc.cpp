syntax on
set ai
set sts=4 ts=4 sw=4
set expandtab autowrite smartindent mouse=a
set showmode showcmd
set timeoutlen=300
set nu rnu

nnoremap <C-\> :w <CR> :!clear && g++ -std=c++17 -O2 -Wall -g % && ./a.out<CR>
inoremap kj <Esc>
