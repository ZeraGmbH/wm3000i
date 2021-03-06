// header datei zeraglobal.h
// hier werden global alle status-, event- usw. informationen definiert 

#ifndef ZERAGLOBAL_H
#define ZERAGLOBAL_H

// rückmeldungen für kommandos zwischen due's  und dee's (erweiterbar)
//-------------------------------------------------------------------------------------------------
#define ACKString "ack"  // acknowledge (kommando verstanden und ausgeführt)
#define NACKString "nak"  // not acknowledge (kommando nicht verstanden)
#define BUSYString "busy" // was wohl (kommando verstanden, device jedoch busy)
#define ERRCONString "errcon"  // error connection (kommando verstanden, keine verbindung zum device) 
#define ERRAUTString "erraut" // error autorisierung (kommando verstanden, client hat aber keine berechtigung)
#define ERRVALString "errval" // kommando verstanden, parameter jedoch fehlerhaft
#define ERRXMLString "errxml" // die verwendete xml datei war fehlerhaft
#define ERRMMEMString "errmmem" // fehler massenspeicher
#define ERRPATHString "errpath" // falsche pfad angabe bzw. pfad existiert nicht
#define ERREXECString "errexec" // fehler bei der ausführung eines kommandos


// mögliche messbereichtypen, werden genutzt rauszufinden ob eine vom messkanal geforderte eigenschaft verfügbar ist 
// ein bereich kann u.U. mehrere 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
enum SenseRangeType {Volt, Ampere}; 

// an jedem bereich "kleben" justagedaten !!!!!
// physikalische bereiche sind tatsächlich vorhandene bereiche
// logische bereiche sind bereiche die angewählt werden können, aber nur der anpassung der dynamik dienen
// linearisierungs bereiche dienen nur als als anker  für justagedaten zur generierung von "zwischenkorrekturen"
// virtuelle bereich dienen nur als anker für justagedaten, wenn z.b. der ad-wandler sep. justiert werden musss
// all diese bereich werden von den kommandos des leiterkartenservers unterstütz, eine ausnahme bildet das
// kommando zur bereichanwahl, dieses lässt nur phys. bzw. log. bereiche zu
 
enum SenseRangeSpec {rngPhys, rngLog, rngLin, rngVirt};

// mögliche statusbits eines messkanals (erweiterbar) werden bei justagedaten verwendet
//----------------------------------------------------------------------------------------------------------------------
enum SenseRangeStatus {RangeDefect = 1,  // 3 bits frei
		           RangeGainJustified = 0x10, 
		           RangeOffsetJustified = 0x20,
		           RangePhaseJustified = 0x40} ; // mehr gibt es erstmal nicht


#endif
