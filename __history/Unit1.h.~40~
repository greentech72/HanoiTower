//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "hanoi_towers.h"
#include <Vcl.Menus.hpp>
#include "Unit2.h"

using std::stack;
using std::vector;
using std::string;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button3;
	TImage *Image1;
	TTimer *Timer1;
	TButton *Button2;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *About1;
	TMenuItem *Exit1;
	TEdit *Edit3;
	TLabel *Label3;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
private:	// User declarations
	void DR(TCanvas *canv, int pin, int pos, int size);
	void CreatePins(TCanvas *canv);
	void Clear(TCanvas *canv);
	void PrintPins(vector<stack<int>> pins, TCanvas *canv);
	void ToggleTimer();
    void move();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
