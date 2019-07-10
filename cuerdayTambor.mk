#makefile
#makefile
cuerdacaso1.png: %.txt Plots_cuerdayTambor.py BelloAna_cuerdayTambor.cpp
	python Plots_cuerdayTambor.py
%.txt: a.out
	./a.out
a.out: BelloAna_cuerdayTambor.cpp
	g++ BelloAna_cuerdayTambor.cpp

#cuerdacaso2.png: %.txt Plots_cuerda.py BelloAna_cuerda.cpp
	#python Plots_cuerda.py
#%.txt: a.out
	#./a.out
#a.out: BelloAna_cuerda.cpp
	#g++ BelloAnaS5C2.cpp

#cuerdacaso3.png: %.txt Plots_cuerda.py BelloAna_cuerda.cpp
	#python Plots_cuerda.py
#%.txt: a.out
	#./a.out
#a.out: BelloAna_cuerda.cpp
	#g++ BelloAnaS5C2.cpp