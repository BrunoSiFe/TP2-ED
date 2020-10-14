

CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp2 
TMPOUT=tp2.testresult

# === REGRAS =====
# ================
# 
# Aqui declaramos as nossas regras de compilacao.
# Para chamar uma regra, podemos simplesmente digitar
# 	make nome_regra
# Exs.:
# 	make ./algoritmoImperial1
# 	make foo.o
# 	make clean
# Cada regra de compilacao tem a seguinte sintaxe:
#
# NOME_OUTPUT: DEPENDENCIAS
# 	CMD
#
# NOME_OUTPUT eh o nome do arquivo que vai ser gerado (ou qualquer nome caso
# nenhum arquivo seja gerado, ex. clean)
# DEPENDENCIAS sao os nomes dos arquivos necessarios para executar essa regra
# de compilacao
# CMD sao os comandos necessarios para executar a regra (por exemplo, chamar o
# gcc)

$(EXEC): algoritmoImperialSelect.cpp  planeta.o
	$(CC) $(CFLAGS) algoritmoImperialSelect.cpp planeta.o -o $(EXEC)

planeta.o: planeta.cpp
	$(CC) $(CFLAGS) -c planeta.cpp -o planeta.o


test: $(EXEC)
	@bash run_test.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf planeta.o


