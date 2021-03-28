***An Object-Oriented C++ implementation of the Enigma Encryption Machine.***

After cloning the repository, initialise an enigma configuration as follows: 

*./enigma plugboards/<plugboard>.rf rotors/<rotors>.rf rotors/<rotorinitialposition>.pos*

The machine requires at least 3 command line arguments (reflector, plugboard, positions) to function.

You can provide as many rotors as necessary.

After the enigma machine was intialised, one can provide messages to encrypt via standard terminal input. 

**Example of one possible configuration with 3 rotors:**

*./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos*
