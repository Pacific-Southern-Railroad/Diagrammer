
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <Dir.h>
#include <Dos.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma link "Grids"
#pragma resource "*.dfm"
TDiagrammerA *DiagrammerA;
//---------------------------------------------------------------------------
__fastcall TDiagrammerA::TDiagrammerA(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::FormCreate(TObject *Sender)
{
 	Edit1->Text="0";
   Edit2->Text="0";
   Status->Text = "PLOTTING";
   Cols = 160;
   Rows = 39;
	arrModified = false;
   CellTile = new Graphics::TBitmap;

   //Load large tile bitmaps

	Tiles->Clear();
	LoadTile("blank.bmp");	//0
   LoadTile("crossingX.bmp");	//1
   LoadTile("trackH.bmp");	//2
   LoadTile("trackV.bmp");	//3
   LoadTile("blockHR.bmp");	//4
   LoadTile("blockHL.bmp");	//5
   LoadTile("diagonalDU.bmp");	//6
   LoadTile("diagonalUD.bmp");	//7
   LoadTile("angleDL.bmp");	//8
   LoadTile("angleDR.bmp");	//9
   LoadTile("angleUL.bmp");	//10
   LoadTile("angleUR.bmp");	//11
   LoadTile("angleVUR.bmp");	//12
   LoadTile("angleVUL.bmp");	//13
   LoadTile("angleVDR.bmp");	//14
   LoadTile("angleVDL.bmp");	//15
   LoadTile("hsignalR.bmp");	//16
   LoadTile("hsignalL.bmp");	//17
   LoadTile("dsignalR.bmp");	//18
   LoadTile("dsignalL.bmp");	//19
   LoadTile("switchMKR.bmp");	//20
   LoadTile("trackRHL.bmp");	//21
   LoadTile("trackRHR.bmp");	//22
   LoadTile("stop.bmp");	//23
   LoadTile("buttonUP.bmp");	//24
   LoadTile("buttonDN.bmp"); //25
   LoadTile("HswitchMKR.bmp"); //26
   LoadTile("detection.bmp");  //27


   for(int i=0; i<3; i++)		//28-30
   {
   	LoadTile("blank.bmp");
   }
   LoadTile("trackYD.bmp");  //31
   LoadTile("trackRH.bmp");	//32
   LoadTile("trackRV.bmp");	//33
   LoadTile("blockRHR.bmp");	//34
   LoadTile("blockRHL.bmp");	//35
   LoadTile("diagonalRDU.bmp");	//36
   LoadTile("diagonalRUD.bmp");	//37
   LoadTile("angleRDL.bmp");	//38
   LoadTile("angleRDR.bmp");	//39
   LoadTile("angleRUL.bmp");	//40
   LoadTile("angleRUR.bmp");	//41
   LoadTile("angleRVUR.bmp");	//42
   LoadTile("angleRVUL.bmp");	//43
   LoadTile("angleRVDR.bmp");	//44
   LoadTile("angleRVDL.bmp");	//45
   LoadTile("hsignalRG.bmp");	//46
   LoadTile("hsignalLG.bmp");	//47
   LoadTile("dsignalRY.bmp");	//48
   LoadTile("dsignalLY.bmp");	//49
   LoadTile("trackGHL.bmp");	//50
   LoadTile("trackGHR.bmp");	//51
   LoadTile("trackY.bmp");		//52
   for(int i=0; i<9; i++)		//53-61
   {
   	LoadTile("blank.bmp");
   }

   LoadTile("trackGH.bmp");	//62
   LoadTile("trackGV.bmp");	//63
   LoadTile("blockGHR.bmp");	//64
   LoadTile("blockGHL.bmp");	//65
   LoadTile("diagonalGDU.bmp");	//66
   LoadTile("diagonalGUD.bmp");	//67
   LoadTile("angleGDL.bmp");	//68
   LoadTile("angleGDR.bmp");	//69
   LoadTile("angleGUL.bmp");	//70
   LoadTile("angleGUR.bmp");	//71
   LoadTile("angleGVUR.bmp");	//72
   LoadTile("angleGVUL.bmp");	//73
   	LoadTile("angleGVDR.bmp");	//74
   	LoadTile("angleGVDL.bmp");	//75
   	LoadTile("hsignalRC.bmp");		//76
   	LoadTile("hsignalLC.bmp");		//77
   	LoadTile("fleetL.bmp");			//78
   	LoadTile("fleetR.bmp");			//79
   	LoadTile("stopA.bmp");			//80
   	LoadTile("stopL.bmp");			//81
    LoadTile("indicatorR.bmp");		//82
    LoadTile("indicatorG.bmp");		//83
    LoadTile("indicatorOut.bmp");	//84

   for (int i=0; i<Cols; i++)
   {
   	for (int j=0; j<Rows; j++)
      {
      	DrawArray[i][j] = 0;
      }
   }
   Pointer = 0;
   Display(Pointer);
   Square = 17;

   DrawGrid1->Visible = true;
   Image1->Visible = false;
   Bitmap->Enabled = true;
   Drawgrid->Enabled = false;

   Plotting = true;
   PastingMoving = false;
   Selecting = false;


   Select->Enabled = true;
   Copy->Enabled = false;
   Paste->Enabled = true;
   Move->Enabled = false;
   Merge->Enabled = false;
   Clear->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::DrawGrid1MouseDown(TObject *Sender,
					 TMouseButton Button, TShiftState Shift, int X, int Y)
{
	long Col, Row;
   DrawGrid1->MouseToCell(X, Y, Col, Row);

	if(Plotting)
   {
    	if(Button == mbRight)
	   {
		  	Pointer = DrawArray[Col][Row];
	  		Display(Pointer);
	   }
   	else
	   {
			DrawArray[Col][Row] = (char)Pointer;
	   	arrModified = true;
      }
   }
   else if(Selecting)
   {
   	DownCol = Col;
	   DownRow = Row;
   	Selecting = true;
   }
   else if(PastingMoving)
   {
   	SMoveRow = Row;
      SMoveCol = Col;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::DrawGrid1MouseUp(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y)
{
	long Col, Row;
	DrawGrid1->MouseToCell(X, Y, Col, Row);

   if(Selecting)
   {
   	UpCol = Col;
      UpRow = Row;

      if(UpCol >= DownCol)
      {
      	Selected.Left = DownCol*Square;
         Selected.Right = UpCol*Square;
         Left = DownCol;
         Width = UpCol - DownCol;
      }
      else
      {
      	Selected.Left = UpCol*Square;
         Selected.Right = DownCol*Square;
         Left = UpCol;
         Width = DownCol - UpCol;
      }
      if(UpRow >= DownRow)
      {
      	Selected.Top = DownRow*Square;
         Selected.Bottom = UpRow*Square;
         Top = DownRow;
         Height = UpRow - DownRow;
      }
      else
      {
      	Selected.Top = UpRow*Square;
         Selected.Bottom = DownRow*Square;
         Top = UpRow;
         Height = DownRow - UpRow;
      }
	   if(Height && Width)
      {
 	   	DrawGrid1->Canvas->FrameRect(Selected);
       	Copy->Enabled = true;
         Move->Enabled = true;
  	   }
      else
      {
      	Select->Enabled = true;
      }
	}
   else if(PastingMoving)
   {
   	if(Row >= SMoveRow)
       	pTop = pTop + (Row - SMoveRow);
      else
      	pTop = pTop - (SMoveRow - Row);
      if(Col >= SMoveCol)
	      pLeft = pLeft + (Col - SMoveCol);
      else
      	pLeft = pLeft - (SMoveCol - Col);

      DrawGrid1->Invalidate();
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::DrawGrid1MouseMove(TObject *Sender,
					 TShiftState Shift, int X, int Y)
{
	long Col, Row;
	DrawGrid1->MouseToCell(X, Y, Col, Row);
   LeftCol = Col;

   Edit1->Text = IntToStr(Col);
   Edit2->Text = IntToStr(Row);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::DrawGrid1DrawCell(TObject *Sender, long Col,
					 long Row, TRect &Rect, TGridDrawState State)
{
   if(PastingMoving && Col >= pLeft && Col < pLeft + pWidth
   					&& Row >= pTop && Row < pTop + pHeight)
	{
	   Tiles->GetBitmap(PasteArray[Col-pLeft][Row-pTop], CellTile);
   }
   else
   {
	   Tiles->GetBitmap(DrawArray[Col][Row], CellTile);
   }
   DrawGrid1->Canvas->Draw(Rect.Left, Rect.Top,(TGraphic*)CellTile);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::New1Click(TObject *Sender)
{
	if (arrModified)
   {
   	int result = Application->MessageBox(
   		"The current file has changed.  Save changes?",
      	"Diagrammer Message", MB_YESNOCANCEL);
	   if (result == IDYES)
   	  	SaveArrayClick(Sender);
      if (result == IDCANCEL)
      	return;
	}

   arrModified = false;
   if (Memo1->Lines->Count > 0)
   	Memo1->Clear();
   SaveArrayDialog->FileName = "";

	for(int i=0; i<Cols; i++)
   	for(int j=0; j<Rows; j++)
	     	DrawArray[i][j] = 0;
   DrawGrid1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::OpenArrayClick(TObject *Sender)
{
	OpenArrayDialog->FileName = "";
   if (OpenArrayDialog->Execute())
   {
   	Memo1->Clear();
      Memo1->Lines->LoadFromFile(OpenArrayDialog->FileName);
      SaveArrayDialog->FileName = OpenArrayDialog->FileName;
      arrModified = false;
   	int ptr=0;

   	strcpy(strArray, Memo1->Text.c_str());

      	for (int j=0; j<Rows; j++)
	   	{
	   		for(int i= 0; i<Cols; i++)
		      {
		         DrawArray[i][j] = (char)(strArray[ptr]-48);
		         ptr++;
		      }
		   }

      DrawGrid1->Invalidate();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SaveArrayAsClick(TObject *Sender)
{
	SaveArrayDialog->Title = "Save As";
	if (SaveArrayDialog->Execute())
   	{
	   int ptr=0;

	   for (int j=0; j<Rows; j++)
	   {
	      for (int i=0; i<Cols; i++)
	      {
	        	strArray[ptr] = (char)(DrawArray[i][j] + 48);
	     		ptr++;
	      }
      }
      ptr++;
      strArray[ptr] = 0;	//terminate string
      Memo1->Text = strArray;
      Memo1->Lines->SaveToFile(SaveArrayDialog->FileName);
   	arrModified = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SaveArrayClick(TObject *Sender)
{
   if(SaveArrayDialog->FileName != "")
   {
      int ptr=0;

      for (int j=0; j<Rows; j++)
      {
         for (int i=0; i<Cols; i++)
         {
         	strArray[ptr] = (char)(DrawArray[i][j] + 48);
      		ptr++;
         }
      }
      ptr++;
      strArray[ptr] = 0;	//terminate string
      Memo1->Text = strArray;
      Memo1->Lines->SaveToFile(SaveArrayDialog->FileName);
   	arrModified = false;
   }
   else
   	SaveArrayAsClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::OpenBitmapClick(TObject *Sender)
{
	OpenBitmapDialog->FileName = "";
   if (OpenBitmapDialog->Execute())
   {
    	Image1->Picture->LoadFromFile(OpenBitmapDialog->FileName);
      SaveBitmapDialog->FileName = OpenBitmapDialog->FileName;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::ClearTilesClick(TObject *Sender)
{
	int X=0;
   int Y=0;

   for (int j=0; j<Rows; j++)
   {
    	for (int i=0; i<Cols; i++)
      {
         if(DrawArray[i][j] != 0)
         {
           	Tiles->GetBitmap(0, CellTile);
      		Image1->Canvas->Draw(X, Y, (TGraphic*)CellTile);
       	}
  			X += HtWd;
  		}
		X = 0;
		Y += HtWd;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::DrawBitmapTilesClick(TObject *Sender)
{
	int X=0;
   int Y=0;
   for (int j=0; j<Rows; j++)
   {
     	for (int i=0; i<Cols; i++)
      {
         if(DrawArray[i][j] != 0)
         {
	   		Tiles->GetBitmap(DrawArray[i][j], CellTile);
   	  		Image1->Canvas->Draw(X, Y, (TGraphic*)CellTile);
         }
  			X += HtWd;
      }
	   X = 0;
	   Y += HtWd;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SaveBitmapAsClick(TObject *Sender)
{
 	SaveBitmapDialog->Title = "Save As";
	if (SaveBitmapDialog->Execute())
   {
	   Image1->Picture->SaveToFile(SaveBitmapDialog->FileName);
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton1Click(TObject *Sender)
{
	Pointer = 20;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton2Click(TObject *Sender)
{
	Pointer = 1;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton3Click(TObject *Sender)
{
	Pointer = 2;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton4Click(TObject *Sender)
{
	Pointer = 3;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton5Click(TObject *Sender)
{
	Pointer = 4;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton6Click(TObject *Sender)
{
	Pointer = 5;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton7Click(TObject *Sender)
{
	Pointer = 6;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton8Click(TObject *Sender)
{
	Pointer = 7;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton9Click(TObject *Sender)
{
	Pointer = 8;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton10Click(TObject *Sender)
{
	Pointer = 9;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton11Click(TObject *Sender)
{
	Pointer = 10;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton12Click(TObject *Sender)
{
	Pointer = 11;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton13Click(TObject *Sender)
{
	Pointer = 12;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton14Click(TObject *Sender)
{
	Pointer = 13;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton15Click(TObject *Sender)
{
	Pointer = 14;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton16Click(TObject *Sender)
{
	Pointer = 15;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton17Click(TObject *Sender)
{
	Pointer = 16;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton18Click(TObject *Sender)
{
	Pointer = 17;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton19Click(TObject *Sender)
{
	Pointer = 18;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton20Click(TObject *Sender)
{
	Pointer = 19;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton25Click(TObject *Sender)
{
	Pointer = 24;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton26Click(TObject *Sender)
{
	Pointer = 25;
  	Display(Pointer);
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::DrawgridClick(TObject *Sender)
{
	DrawGrid1->Visible = true;
   Image1->Visible = false;
   Bitmap->Enabled = true;
   Drawgrid->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::BitmapClick(TObject *Sender)
{
	DrawGrid1->Visible = false;
   Image1->Visible = true;
   Bitmap->Enabled = false;
   Drawgrid->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton29Click(TObject *Sender)
{
	if(Pointer<85)
   {
   	Pointer++;
	  	Display(Pointer);
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton30Click(TObject *Sender)
{
	if(Pointer>0)
   {
   	Pointer--;
     	Display(Pointer);
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SelectClick(TObject *Sender)
{
   Select->Enabled = false;
   Copy->Enabled = false;
   Paste->Enabled = false;
   Move->Enabled = false;
   Merge->Enabled = false;
   Clear->Enabled = false;

   Status->Text = "SELECTING";

   Plotting = false;
   PastingMoving = false;
   Selecting = true;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::CopyClick(TObject *Sender)
{
   Select->Enabled = true;
   Copy->Enabled = false;
   Paste->Enabled = true;
   Move->Enabled = false;
   Merge->Enabled = false;
   Clear->Enabled = false;

   Status->Text = "PLOTTING";

   Plotting = true;
   PastingMoving = false;
   Selecting = false;

	int ptr = 0;

   for (int j=Top; j<Top+Height; j++)
   {
      for (int i=Left; i<Left+Width; i++)
      {
         strArray[ptr] = (char)(DrawArray[i][j] + 48);
         ptr++;
      }
   }
   ptr++;
   strArray[ptr] = 0;

   Memo1->Clear();
   Memo1->Text = strArray;
   Memo1->Lines->Insert(0, IntToStr(Height).TrimRight());
   Memo1->Lines->Insert(1, IntToStr(Width).TrimRight());
   Memo1->SelectAll();
   Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::PasteClick(TObject *Sender)
{
   Select->Enabled = false;
   Copy->Enabled = false;
   Paste->Enabled = false;
   Move->Enabled = false;
   Merge->Enabled = true;
   Clear->Enabled = true;

   Status->Text = "PASTING";

   Plotting = false;
   PastingMoving = true;
   Selecting = false;

   Memo1->Clear();
   Memo1->PasteFromClipboard();

   if(Memo1->Text != "")
   {
	  pHeight = StrToInt(Memo1->Lines->Strings[0]);
	  pWidth = StrToInt(Memo1->Lines->Strings[1]);
      Memo1->Lines->Delete(0);
      Memo1->Lines->Delete(0);
      strcpy(strArray, Memo1->Text.c_str());
      pLeft = LeftCol;

		int ptr=0;
	   for (int j=0; j<pHeight; j++)
		{
			for(int i=0; i<pWidth; i++)
		   {
		      PasteArray[i][j] = (char)(strArray[ptr] - 48);
		      ptr++;
		   }
		}
	   DrawGrid1->Invalidate();
   }
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::MergeClick(TObject *Sender)
{
   Select->Enabled = true;
   Copy->Enabled = false;
   Paste->Enabled = true;
   Move->Enabled = false;
   Merge->Enabled = false;
   Clear->Enabled = false;

   Status->Text = "PLOTTING";

   Plotting = true;
   PastingMoving = false;
   Selecting = false;

	for(int j=0; j<pHeight; j++)
   {
   	for(int i=0; i<pWidth; i++)
      {
      	DrawArray[i+pLeft][j+pTop] = PasteArray[i][j];
      }
   }
	pLeft = pTop = 0;
   DrawGrid1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::ClearClick(TObject *Sender)
{
   Select->Enabled = true;
   Copy->Enabled = false;
   Paste->Enabled = true;
   Move->Enabled = false;
   Merge->Enabled = false;
   Clear->Enabled = false;

   Status->Text = "PLOTTING";

   Plotting = true;
   PastingMoving = false;
   Selecting = false;

	for(int j=0; j<pHeight; j++)
   {
   	for(int i=0; i<pWidth; i++)
      {
      	DrawArray[i+pLeft][j+pTop] = 0;
      }
   }
   pLeft = pTop = 0;
   DrawGrid1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::MoveClick(TObject *Sender)
{
   Select->Enabled = false;
   Copy->Enabled = false;
   Paste->Enabled = false;
   Move->Enabled = false;
   Merge->Enabled = true;
   Clear->Enabled = true;

   Status->Text = "MOVING";

   Plotting = false;
   PastingMoving = true;
   Selecting = false;

   for (int j=Top; j<Top+Height; j++)
   {
      for (int i=Left; i<Left+Width; i++)
      {
         PasteArray[i-Left][j-Top] = DrawArray[i][j];
         DrawArray[i][j] = 0;
      }
   }
   pTop = Top;
   pLeft = Left;
   pHeight = Height;
   pWidth = Width;
   DrawGrid1->Invalidate();
}
//---------------------------------------------------------------------------
void TDiagrammerA::LoadTile(String Name)
	{
   	Tiles->FileLoad(rtBitmap,("ScreenTiles\\" + Name), clWhite);
   }
//---------------------------------------------------------------------------
void TDiagrammerA::Display(int Pointer)
	{
 	  Tiles->Draw(SelectedTile->Canvas, 0, 0, Pointer);
      Edit3->Text = IntToStr(Pointer);
      SelectedTile->Invalidate();
   }
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::ScrollerClick(TObject *Sender)
{
	DrawGrid1->ColCount = 450;
    DrawGrid1->RowCount = 39;
	Cols = 450;
    Rows = 39;
    Image1->Height = Rows*16;
    Image1->Width = Cols*16;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::WideClick(TObject *Sender)
{
	DrawGrid1->ColCount = 160;
	Cols = 160;
    DrawGrid1->RowCount = 39;
    Rows = 39;
    Image1->Height = Rows*16;
    Image1->Width = Cols*16;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::RectangleClick(TObject *Sender)
{
	DrawGrid1->ColCount = 70;
	Cols = 70;
    DrawGrid1->RowCount = 50;
    Rows = 50;
    Image1->Height = Rows*16;
    Image1->Width = Cols*16;
}
//---------------------------------------------------------------------------

void __fastcall TDiagrammerA::ScrollClick(TObject *Sender)
{
	DrawGrid1->ColCount = 480;
	Cols = 480;
    DrawGrid1->RowCount = 39;
    Rows = 39;
    Image1->Height = Rows*16;
    Image1->Width = Cols*16;
}
//---------------------------------------------------------------------------
void __fastcall TDiagrammerA::SpeedButton21Click(TObject *Sender)
{
	Pointer = 31;
    Display(Pointer);
}
//---------------------------------------------------------------------------
