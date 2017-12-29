CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

COINCLASSESSRCDIR = ../../src/keynode/CoinClasses
KEYNODESRCDIR = ../../src/keynode
CRYPTORCDIR = ../../src/crypto
COMPATRCDIR = ../../src/compat
SRCDIR = ../../src

SEEDHEADERS = \
    $(CRYPTORCDIR)/mnemoniccode.h \
    $(CRYPTORCDIR)/pbkdf2sha512.h \
    $(CRYPTORCDIR)/common.h \
    $(CRYPTORCDIR)/hmac_sha512.h \
    $(CRYPTORCDIR)/sha512.h \
    $(COMPATRCDIR)/byteswap.h \
    $(COMPATRCDIR)/endian.h

TREEHEADERS = \
    $(COINCLASSESSRCDIR)/hdkeys.h \
    $(COINCLASSESSRCDIR)/hash.h \
    $(COINCLASSESSRCDIR)/secp256k1.h \
    $(COINCLASSESSRCDIR)/BigInt.h \
    $(COINCLASSESSRCDIR)/uchar_vector.h


generate-key: main.cpp bpgeneratekey.o keynode.o logger.o hdkeys.o keytreeutil.o \
	mnemoniccode.o pbkdf2sha512.o hmac_sha512.o sha512.o
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $< bpgeneratekey.o keynode.o logger.o \
	hdkeys.o keytreeutil.o mnemoniccode.o pbkdf2sha512.o hmac_sha512.o sha512.o -lcrypto



bpgeneratekey.o: bpgeneratekey.cpp keynode.o mnemoniccode.o
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ -c $<



keytreeutil.o: keytreeutil.cpp
	$(CXX)  $(CXXFLAGS) -I$(SRCDIR) -o $@ -c $<

keynode.o: $(KEYNODESRCDIR)/keynode.cpp $(COINCLASSESSRCDIR)/Base58Check.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

logger.o: $(KEYNODESRCDIR)/logger.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

hdkeys.o: $(COINCLASSESSRCDIR)/hdkeys.cpp $(TREEHEADERS) 
	$(CXX) $(CXXFLAGS) -o $@ -c $<




mnemoniccode.o: $(CRYPTORCDIR)/mnemoniccode.cpp pbkdf2sha512.o
	$(CXX)  $(CXXFLAGS) -o $@ -c $<

pbkdf2sha512.o: $(CRYPTORCDIR)/pbkdf2sha512.cpp hmac_sha512.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

hmac_sha512.o: $(CRYPTORCDIR)/hmac_sha512.cpp sha512.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

sha512.o: $(CRYPTORCDIR)/sha512.cpp $(SEEDHEADERS) $(CRYPTORCDIR)/common.h 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	-rm -rf *.o $(KEYNODESRCDIR)/*.o $(COINCLASSESSRCDIR)/*.o *~ $(KEYNODESRCDIR)/*~ $(COINCLASSESSRCDIR)/*.o~ \
	$(CRYPTORCDIR)/*.o $(COMPATRCDIR)/*.o *~ $(CRYPTORCDIR)/*~ $(COMPATRCDIR)/*.o~ generate-key.dSYM generate-key
