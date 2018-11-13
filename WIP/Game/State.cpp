#include "State.h"

////https://discuss.cocos2d-x.org/t/solved-need-help-in-rapidjson-object-parsing/33429/2

State::State() {}

State::State(HWND hWnd, char* name, D3DCOLOR transcolor,int animation_delay,int ID)
{
	//Gán 1 số thứ linh tinh
	this->hWnd = hWnd;  
	this->ID = ID;
	this->JsonFileName = dxgraphics::standardizedSourceName(name);  // sửa lại đường dẫn
	this->title_set.trans_color = transcolor; //màu lọc 
	this->state_properties.Animation_Delay = animation_delay; //Đỗ trễn animation ( tính bằng frame )
	this->state_properties.Curframe_Id = 0; // này vs phía dưới là 2 cái biến đếm
	this->state_properties.Animation_Count = 0;
}

int State::Create()
{

	//load Json content
	try
	{	
		//Load Json content
		jsonDocument = dxgraphics::LoadJSonDocument(this->JsonFileName);
	}
	catch (const std::exception&)
	{
		MessageBox(hWnd, "Error when load json file", "error", MB_OK);
		return 0;
	}

	const rapidjson::Value& titlesheet = jsonDocument["tilesets"];

	this->title_set.First_gid = titlesheet[0]["firstgid"].GetInt();  // thứ tự của ô đầu tiên trong 1 tile set ( có thể 1 map có nhiều tile set và id của set thứ 2 sẽ bằng ô cuối set 1 +1 nên t phải lưu trữ lại thông số này để sữ dụng cho việc tính
	this->title_set.source = new char[titlesheet[0]["image"].GetStringLength()];
	this->title_set.source = _strdup(titlesheet[0]["image"].GetString());  // tên file png ( tile set)
	this->title_set.titlesheet_colums = titlesheet[0]["columns"].GetInt(); 
	this->title_set.titlesheet_height = titlesheet[0]["tileheight"].GetInt();
	this->title_set.titlesheet_width = titlesheet[0]["tilewidth"].GetInt();
	// Load mảng animation
	const rapidjson::Value& layer = jsonDocument["layers"];  
	const rapidjson::Value& data = layer[0]["data"];
	this->state_properties.Arrdata = new int[data.Size()];
	this->state_properties.Animation_Numberofsprite = data.Size();

	for (int i = 0; i < data.Size(); i++)
	{
		this->state_properties.Arrdata[i] = data[i].GetInt();
	}

	//load sprite image
	HRESULT result = D3DXCreateSprite(dxgraphics::getInstance()->getDevice() , &sprite_handler);
	if (result != D3D_OK)
	{
		MessageBox(hWnd, "Somthing wrong when creat sprite handler", "error", MB_OK);
		return 0;
	}

	sprite_texture = dxgraphics::LoadTexture(dxgraphics::standardizedSourceName(this->title_set.source), this->title_set.trans_color);
	if (sprite_texture == NULL)
	{
		MessageBox(hWnd, "Load Textture faild", "error", MB_OK);
		return 0;
	}
	
	start = GetTickCount();
	return 1;
}

void State::DrawCurframe(D3DXVECTOR3 position)
{
	// Cái đống phía dưới này xem sách
	//if (GetTickCount() - start > ANIMATIONUPDATEDELAY) {
		/*dxgraphics::d3ddev->ColorFill(dxgraphics::backbuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));*/

		start = GetTickCount();
		sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);

		int Frameid = this->state_properties.Arrdata[this->state_properties.Curframe_Id];
		Frameid = Frameid - this->title_set.First_gid;
		int left = (Frameid % this->title_set.titlesheet_colums) * this->title_set.titlesheet_width;
		int top = (Frameid / this->title_set.titlesheet_colums) * this->title_set.titlesheet_height;
		int right = left + this->title_set.titlesheet_width;
		int bottm = top + this->title_set.titlesheet_height;

		RECT rect = { left,top,right,bottm };
		
		sprite_handler->Draw
		(
			sprite_texture,
			&rect,
			NULL,
			&position,
			this->title_set.trans_color
		);
		if (++this->state_properties.Animation_Count > this->state_properties.Animation_Delay) {
			this->state_properties.Animation_Count = 0;
			if (++this->state_properties.Curframe_Id >= this->state_properties.Animation_Numberofsprite) {
				this->state_properties.Curframe_Id = 0;
			}
		}
		sprite_handler->End();
	/*}*/
}

void State::refresh() {
	this->state_properties.Animation_Count = 0;
	this->state_properties.Curframe_Id = 0;
}
State::~State()
{
}
