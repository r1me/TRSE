#include "compilerz80.h"


void CompilerZ80::InitAssemblerAnddispatcher(QSharedPointer<AbstractSystem> system)
{
    m_assembler = QSharedPointer<AsmZ80>(new AsmZ80());//
    m_dispatcher = QSharedPointer<ASTdispatcherZ80>(new ASTdispatcherZ80());
//    m_assembler->Asm("CPU "+m_projectIni->getString("cpu_Z80_system"));
    m_assembler->IncludeFile(":resources/code/gameboy/defs.s");
    m_assembler->IncludeFile(":resources/code/gameboy/init.s");


}

void CompilerZ80::Connect()
{
    m_assembler->m_source<<m_parser.m_parserAppendix;

    m_assembler->EndMemoryBlock();
    m_assembler->Connect();


    m_assembler->m_wram->m_source.insert(0,"		SECTION	\"WRAM\",WRAM0[$C000]"		);

    m_assembler->m_source <<m_assembler->m_wram->m_source;

    m_assembler->m_hram->m_source.insert(0,"		SECTION	\"HRAM\",HRAM[$FF8A]"		);
    m_assembler->m_source <<m_assembler->m_hram->m_source;


}
