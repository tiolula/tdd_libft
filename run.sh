#!/bin/bash

GREEN='\033[0;32m'
NO_COLOR='\033[0m' # No Color

cd tests && \
make && \
make leakfull && \
cd ../src && \
make && \
norminette && \
echo ""  && \
echo -e "${GREEN}SUCESSO!${NO_COLOR}" 