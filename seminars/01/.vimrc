set nocompatible
set encoding=utf-8
set termencoding=utf-8
set fileencodings=utf-8,cp1251,koi8-r

set si
set tabstop=4
set shiftwidth=4
set expandtab
set smarttab

set number
set cursorline
set t_Co=256
syntax on

fun! <SID>StripTrailingWhitespaces()
    let l = line(".")
    let c = col(".")
    %s/\s\+$//e
    call cursor(l, c)
endfun

autocmd FileType h,c,cpp,java,php,py autocmd BufWritePre <buffer> :call <SID>StripTrailingWhitespaces()
