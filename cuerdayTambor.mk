#makefile
#makefile
cuerdacaso1.png: %.txt Plots_cuerdayTambor.py BelloAna_cuerdayTambor.cpp
	python Plots_cuerdayTambor.py
%.txt: a.out
	./a.out
a.out: BelloAna_cuerdayTambor.cpp
	g++ BelloAna_cuerdayTambor.cpp

cuerdacaso2.png: %.txt Plots_cuerdayTambor.py BelloAna_cuerdayTambor.cpp
	python Plots_cuerdayTambor.py
%.txt: a.out
	./a.out
a.out: BelloAna_cuerdayTambor.cpp
	g++ BelloAna_cuerdayTambor.cpp

cuerdacaso3.png: %.txt Plots_cuerdayTambor.py BelloAna_cuerdayTambor.cpp
	python Plots_cuerdayTambor.py
%.txt: a.out
	./a.out
a.out: BelloAna_cuerdayTambor.cpp
	g++ BelloAna_cuerdayTambor.cpp