//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void TForm1::Clear(TCanvas *canv){
	auto pc = canv->Pen->Color;
	auto bc = canv->Brush->Color;
	canv->Pen->Color = clWhite;
	canv->Brush->Color = clWhite;
	canv->Rectangle(Rect(0, 0, 530, 400));
	canv->Pen->Color = pc;
	canv->Brush->Color = bc;
}
//---------------------------------------------------------------------------
void TForm1::DR(TCanvas *canv, int pin, int pos, int size){
	int x;
	if(pin == 0)
		x = 95;
	else if(pin == 1)
		x = 268;
	else
		x = 440;

	//int y = 43 * (8 - pos) + 3 * (8 - pos) / 2 + 10;
	int y = 31 * (11 - pos) + (11 - pos) + 22;

	size = (size+1) * 7;

	canv->Ellipse(Rect(x + size, y - 14, x - size, y + 14));
}
//---------------------------------------------------------------------------
void TForm1::CreatePins(TCanvas *canv){
	canv->MoveTo(15, 390);
	canv->LineTo(175, 390);

	canv->MoveTo(185, 390);
	canv->LineTo(350, 390);

	canv->MoveTo(360, 390);
	canv->LineTo(520, 390);

	canv->MoveTo(95, 390);
	canv->LineTo(95, 40);

	canv->MoveTo(267, 390);
	canv->LineTo(267, 40);

	canv->MoveTo(440, 390);
	canv->LineTo(440, 40);
}
//---------------------------------------------------------------------------
void TForm1::PrintPins(vector<stack<int>> pins, TCanvas *canv){
Clear(Image1->Canvas);
CreatePins(Image1->Canvas);
	for(int i = 0; i < 3; i++){
		while(pins[i].size() > 0){
			DR(canv, i, pins[i].size()-1, pins[i].top());
			pins[i].pop();
		}
	}
}
//---------------------------------------------------------------------------
void TForm1::ToggleTimer(){
	if(!Timer1->Enabled){
		Timer1->Enabled = true;
		Button2->Caption = "Stop";
	}
	else{
		Button2->Caption = "Start";
		Timer1->Enabled = false;
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Image1->Canvas->Pen->Color = clWebMediumTurquoise;
Image1->Canvas->Brush->Color = clWebGold;
Image1->Canvas->Pen->Width = 4;

CreatePins(Image1->Canvas);

//Image1->Canvas->Rectangle(Rect(95 - 80 ,368 - 22, 95 + 80,368 + 22));
/*DR( Image1->Canvas, 2, 0, 8);
DR( Image1->Canvas, 2, 1, 7);
DR( Image1->Canvas, 2, 2, 6);
DR( Image1->Canvas, 2, 3, 5);
DR( Image1->Canvas, 2, 4, 4);
DR( Image1->Canvas, 2, 5, 3);
DR( Image1->Canvas, 2, 6, 2);
DR( Image1->Canvas, 2, 7, 1);*/
Timer1->Interval = StrToInt(Edit3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
ListBox1->Items->Clear();
if(Edit1->Text == "" || StrToInt(Edit1->Text) > 11 || StrToInt(Edit1->Text) < 1){
	ListBox1->Items->Add( "Please, Enter correct number" );
	return;
}
disk_am = StrToInt(Edit1->Text);
Clear(Image1->Canvas);
CreatePins(Image1->Canvas);

//for(int i = 0; i < disk_am; i++){
//	DR(Image1->Canvas,0, i, disk_am - i);
//}

res = generate_moves(disk_am);
for(int i = 0; i < res.size(); i++){
	ListBox1->Items->Add( res[i].c_str() );
}
Edit2->Text = (res.size());

////////
pins = generate_pins(disk_am);
PrintPins(pins, Image1->Canvas);
////////
}
//---------------------------------------------------------------------------
void TForm1::move(){
int sel = ListBox1->ItemIndex;
pins = generate_pins(disk_am);
for(int i = 0; i <= sel; i++){
	do_move(&pins, res[i]);
}
PrintPins(pins, Image1->Canvas);

}

//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
	move();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
ToggleTimer();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if(ListBox1->ItemIndex+1 != StrToInt(Edit2->Text)){
	ListBox1->ItemIndex++;
	move();
}
else if(ListBox1->ItemIndex+1 == StrToInt(Edit2->Text)){
	ToggleTimer();
	ListBox1->ItemIndex = -1;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::About1Click(TObject *Sender)
{
// About button here
TForm2 *Form = new TForm2( this );
Form->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
if(Edit3->Text == ""){
    return;
}
if(Timer1->Enabled){
    ToggleTimer();
}
Timer1->Interval = StrToInt(Edit3->Text);
}
//---------------------------------------------------------------------------
