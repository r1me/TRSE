#ifndef SYSTEMMOS6502_H
#define SYSTEMMOS6502_H

#include "source/Compiler/systems/abstractsystem.h"
#include "source/Compiler/misc/machinecodeanalyzer.h"
#include <QMessageBox>
#include "source/messages.h"


class SystemMOS6502 : public AbstractSystem
{
public:
    SystemMOS6502(QSharedPointer<CIniFile> settings, QSharedPointer<CIniFile> proj) : AbstractSystem(settings, proj) {
        m_allowedGlobalTypeFlags << "compressed"<<"pure"<<"pure_variable" <<"pure_number" << "signed" <<"no_term" <<"invert";
        m_allowedProcedureTypeFlags << "pure"<<"pure_variable" <<"pure_number" << "signed" <<"no_term" <<"invert" <<"global" <<"stack";
        m_supportsExomizer = true;
        m_registers << "_a"<<"_x" <<"_y" <<"_ax" <<"_ay" <<"_xy";
        m_canRunAsmFiles = true;
        m_allowClasses = true; // EXPERIMENTAL


    }

    MachineCodeAnalyzer m_mca;


    virtual void Assemble(QString& text, QString file, QString currentDir, QSharedPointer<SymbolTable>  symTab) override;
    virtual void PostProcess(QString& text, QString file, QString currentDir) override;

    virtual QString getTripePointerType() override {
        return "uint16";
    }

    virtual bool useZeroPagePointers() override { return true;}

    virtual bool AllowPointerInStructs() override {return false;}

    bool VerifyMachineCodeZP(QString fname);
    // OBSOLETE
    void CreateDiskC1541(QString currentDir, QString filename, QString iniData, bool addPrg, QString& text);
    // IN USE
    void CreateDiskInternal(QString currentDir, QString filename, QString iniData, bool addPrg, QString& text, QString diskName);
    bool BuildDiskFiles(QString currentDir, QStringList& d64Params, QString iniData);
    bool BuildDiskFilesCC1541(QString currentDir, QStringList& d64Params, QString iniData, QString &text);

    void ApplyDirArt(QString currentDir, QString dirart, QString disk, QString& text);

    void DefaultValues() override;

    QString CompressFile(QString fileName) override
    {
        return CompressLZ4(fileName);
    }

    QStringList CompressData(QStringList& inData, QString& string) override;

    void applyEmulatorParametersVICE(QStringList& params, QString debugFile, QString filename);

    TokenType::Type getSystemPointerArrayType() override {
        return TokenType::INTEGER;
    }

    virtual void PrepareInitialAssembler(Assembler* as) override;


};

#endif // SYSTEMMOS6502_H
