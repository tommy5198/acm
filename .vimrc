execute pathogen#infect()
set expandtab
set shiftwidth=4
set softtabstop=4
set autoindent
set cindent
set hlsearch
set cursorline
set rnu
set sm
set bg=dark
syntax on
:autocmd FileType make setlocal noexpandtab
filetype plugin on
inoremap "      ""<Left>
inoremap ""     "
inoremap {      {}<Left>
inoremap /*     /**/<Left><Left>
inoremap (      ()<Left>
inoremap (<CR>  (<CR>)<Esc>0
inoremap ((     (
inoremap ()     ()
inoremap {<CR>  {<CR>}<Esc>O
inoremap /*<CR> /*<CR><BS>*/<Esc>O
inoremap /**    /*
inoremap {{     {
inoremap {}     {}
inoremap <>     <><Left>
nnoremap \o o<ESC>o
nnoremap \p o<ESC>p
nnoremap \s xp
