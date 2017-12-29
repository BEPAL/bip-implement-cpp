CXX = g++
CXXFLAGS = -std=c++0x -Wall -g

COINCLASSESSRCDIR = ../../src/keynode/CoinClasses
KEYNODESRCDIR = ../../src/keynode
TREEDIR = ../../src


HEADERS = \
    $(COINCLASSESSRCDIR)/hdkeys.h \
    $(COINCLASSESSRCDIR)/hash.h \
    $(COINCLASSESSRCDIR)/secp256k1.h \
    $(COINCLASSESSRCDIR)/BigInt.h \
    $(COINCLASSESSRCDIR)/uchar_vector.h


kt: main.cpp keynode.o logger.o hdkeys.o keytreeutil.o
	$(CXX) $(CXXFLAGS) -I$(TREEDIR) -o $@ $< keynode.o logger.o hdkeys.o keytreeutil.o -lcrypto

keytreeutil.o: keytreeutil.cpp
	$(CXX)  $(CXXFLAGS) -I$(TREEDIR) -o $@ -c $<

keynode.o: $(KEYNODESRCDIR)/keynode.cpp $(COINCLASSESSRCDIR)/Base58Check.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

logger.o: $(KEYNODESRCDIR)/logger.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

hdkeys.o: $(COINCLASSESSRCDIR)/hdkeys.cpp $(HEADERS) 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	-rm -rf *.o $(KEYNODESRCDIR)/*.o $(COINCLASSESSRCDIR)/*.o *~ $(KEYNODESRCDIR)/*~ $(COINCLASSESSRCDIR)/*.o~ kt.dSYM kt
