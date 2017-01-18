#include "Bootil/Bootil.h"
#include "AddonReader.h"

using namespace Bootil;

int main( int argc, char** argv )
{
	Debug::SuppressPopups(true);
	CommandLine::Set(argc, argv);

	BString gmaFile = CommandLine::GetArg(0);
	BString outputDirectory = CommandLine::GetArg(1);

	if (gmaFile.empty())
		Output::Error("Usage: gmaextract in.gma [outdir]\n");

	if (!File::Exists(gmaFile))
		Output::Error("File does not exist!\n");

	if (outputDirectory.empty())
		outputDirectory = String::File::GetStripExtension(gmaFile);

	String::File::FixSlashes(outputDirectory);
	String::Util::TrimRight(outputDirectory, "/");
	outputDirectory = outputDirectory + "/";
	Addon::Reader addon;

	if (!addon.ReadFromFile(gmaFile))
		Output::Error("There was a problem opening the file.\n");

	if (!addon.Parse())
		Output::Error("There was a problem parsing the file.\n");

	Output::Msg("Extracting Files:\n");
	BOOTIL_FOREACH_CONST(entry, addon.GetList(), Addon::FileEntry::List)
	{
		Output::Msg("\t%s [%s]\n", entry->strName.c_str(), String::Format::Memory(entry->iSize).c_str());
		File::CreateFolder(outputDirectory + String::File::GetStripFilename(entry->strName), true);
		AutoBuffer filecontents;

		if (addon.ReadFile(entry->iFileNumber, filecontents))
			File::Write(outputDirectory + entry->strName, filecontents);
		else
			Output::Warning("\t\tCouldn't extract!");
	}
	Output::Msg("Done!\n");

	return 0;
}
