CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

CRYPTORCDIR = ../../src/crypto
COMPATRCDIR = ../../src/compat
SRCDIR = ../../src


HEADERS = \
    $(CRYPTORCDIR)/mnemoniccode.h \
    $(CRYPTORCDIR)/pbkdf2sha512.h \
    $(CRYPTORCDIR)/common.h \
    $(CRYPTORCDIR)/hmac_sha512.h \
    $(CRYPTORCDIR)/sha512.h \
    $(COMPATRCDIR)/byteswap.h \
    $(COMPATRCDIR)/endian.h





seed: main.cpp mnemoniccode.o pbkdf2sha512.o hmac_sha512.o sha512.o
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -o $@ $< mnemoniccode.o pbkdf2sha512.o hmac_sha512.o sha512.o

mnemoniccode.o: $(CRYPTORCDIR)/mnemoniccode.cpp pbkdf2sha512.o
	$(CXX)  $(CXXFLAGS) -o $@ -c $<

pbkdf2sha512.o: $(CRYPTORCDIR)/pbkdf2sha512.cpp hmac_sha512.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

hmac_sha512.o: $(CRYPTORCDIR)/hmac_sha512.cpp sha512.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

sha512.o: $(CRYPTORCDIR)/sha512.cpp $(HEADERS) $(CRYPTORCDIR)/common.h 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	-rm -rf *.o $(CRYPTORCDIR)/*.o $(COMPATRCDIR)/*.o *~ $(CRYPTORCDIR)/*~ $(COMPATRCDIR)/*.o~ seed.dSYM seed
