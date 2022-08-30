//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include "Grids.hpp"
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Menus.hpp>
#include <vcl\ComCtrls.hpp>

const HtWd = 16;
//---------------------------------------------------------------------------
class TDiagrammerA : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDrawGrid *DrawGrid1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TSpeedButton *SpeedButton20;
	TMemo *Memo1;
	TOpenDialog *OpenArrayDialog;
	TSaveDialog *SaveArrayDialog;
	TMainMenu *MainMenu1;
	TPanel *Panel2;
	TMenuItem *File;
	TMenuItem *New1;
	TMenuItem *SaveArray;
	TMenuItem *SaveArrayAs;
	TMenuItem *OpenArray;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TLabel *Label2;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TSpeedButton *Drawgrid;
	TSpeedButton *Bitmap;
	TEdit *Edit3;
	TLabel *Label3;
	TSpeedButton *SpeedButton29;
	TSpeedButton *SpeedButton30;
	TLabel *Label6;
	TSaveDialog *SaveBitmapDialog;
	TMenuItem *SaveBitmapAs;
	TImage *Image1;
	TImage *SelectedTile;
	TImageList *Tiles;
	TButton *Select;
	TButton *Copy;
	TButton *Paste;
	TButton *Merge;
	TButton *Clear;
	TButton *Move;
	TEdit *Status;
	TOpenDialog *OpenBitmapDialog;
	TMenuItem *OpenBitmap;
	TMenuItem *SaveBitmap1;
	TMenuItem *ClearTiles;
	TMenuItem *DrawBitmapTiles;
	TMenuItem *N2;
	TRadioButton *Scroller;
	TRadioButton *Wide;
	TRadioButton *Rectangle;
	TRadioButton *Scroll;
	TSpeedButton *SpeedButton21;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DrawGrid1MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y);

	
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall OpenArrayClick(TObject *Sender);
	void __fastcall SaveArrayAsClick(TObject *Sender);
	void __fastcall SaveArrayClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall DrawGrid1DrawCell(TObject *Sender, long Col, long Row,
	TRect &Rect, TGridDrawState State);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall SpeedButton16Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton19Click(TObject *Sender);
	void __fastcall SpeedButton20Click(TObject *Sender);
	void __fastcall SpeedButton25Click(TObject *Sender);
	void __fastcall SpeedButton26Click(TObject *Sender);
	void __fastcall DrawgridClick(TObject *Sender);
	void __fastcall BitmapClick(TObject *Sender);
	void __fastcall DrawGrid1MouseMove(TObject *Sender, TShiftState Shift, int X,
	int Y);
	void __fastcall SpeedButton29Click(TObject *Sender);
	void __fastcall SpeedButton30Click(TObject *Sender);
	void __fastcall SaveBitmapAsClick(TObject *Sender);
	void __fastcall SelectClick(TObject *Sender);
	void __fastcall DrawGrid1MouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y);
	void __fastcall CopyClick(TObject *Sender);
	void __fastcall PasteClick(TObject *Sender);
	void __fastcall MergeClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall MoveClick(TObject *Sender);
	void __fastcall OpenBitmapClick(TObject *Sender);
	void __fastcall ClearTilesClick(TObject *Sender);
	void __fastcall DrawBitmapTilesClick(TObject *Sender);

	void __fastcall ScrollerClick(TObject *Sender);
	void __fastcall WideClick(TObject *Sender);
	void __fastcall RectangleClick(TObject *Sender);

	void __fastcall ScrollClick(TObject *Sender);
	void __fastcall SpeedButton21Click(TObject *Sender);
private:	// User declarations

   void LoadTile(String Name);
   void TDiagrammerA::Display(int Pointer);
   Graphics::TBitmap *CellTile;
   int Cols, Rows;
   char DrawArray[480][50];
   char PasteArray[480][50];
   bool Selecting;
   bool PastingMoving;
   bool Plotting;
   char strArray[24000];
   int Pointer;
   bool arrModified;
   int DownCol, DownRow, UpCol, UpRow;
   int Top, Left, Height, Width;
   int pTop, pLeft, pHeight, pWidth;
   int SMoveRow, SMoveCol, EMoveRow, EMoveCol;
   int Square;
   int LeftCol;
   TRect Selected;

public:		// User declarations
	__fastcall TDiagrammerA(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDiagrammerA *DiagrammerA;
//---------------------------------------------------------------------------
#endif
 