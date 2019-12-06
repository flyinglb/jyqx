
// Room: /d/yanziwu/hupan.c
// Date: Feb.14.1998 by Java

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
         set("short", "̫������");
         set("long", @LONG
̫��(hu)������֮�䡣���������������֮ˮ�����ڴˣ��������
��ų����������������Ψ������Զ�������۽Ա̣���ʮ����Դ�ͦ
����������ǧ�겨��֮�У�ʹ���Ľ�󿪣�ֱ�����쳤Х�����ܱ��ϲ
�֡�
LONG );
        set("exits", ([
            "northeast" : "/d/suzhou/road5",
        ]));

        set("item_desc", ([
            "hu":"�����ϴ���һҶС�ۣ�����һ��������������Ϸˮ����(yell)һ�����԰ɡ�\n",
        ]));

        set("outdoors", "shaolin");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"xiaozhou")) )
            room = load_object(__DIR__"xiaozhou");
        if( room = find_object(__DIR__"xiaozhou") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"xiaozhou");
                room->set("exits/out", __FILE__);
                message("vision", "һβС�ۻ�����ʻ�˹�����һ��������Ů����������ۡ�\n", this_object() );
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ú�������������������������������\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һβС����һ��������Ůϸ��˵����ٯ��ɶ���塣\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "��Ů���һ�㣬С���밶����Ļ�ȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"xiaozhou") )
    {
        room->delete("exits/out");
        message("vision",
"\n��Ů˵��һ��������ඡ������������壬����һ��֮�£�˵��������
�ʡ�Ȼ�����һ�㣬��������Ļ�ȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"xiaozhou") )
    {
        room->set("exits/out", __DIR__"muti");
message("vision","��Ů˵: ���������ϰ��ɡ������漴һ����ݣ����۲��á�\n",room);
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"xiaozhou") ) {
        room->delete("exits/out");
        message("vision","��Ů���һ�㣬����С�۵����в���Ϸˮ��\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������"+arg+"��������\n",this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"xiaozhou") )
        room->delete("yell_trigger"); 
}
