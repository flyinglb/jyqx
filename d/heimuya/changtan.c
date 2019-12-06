// Room: /d/heimuya/changtan.c

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
    set("short", "��̲");
    set("long", @LONG
��Ƭ��̲��ʱ�����½̽��ڳ˴�(boat)������̲ͷ����һ��
���½̵����ģ��������������½̵������Ƶģ����Ծ��ܽ�����
�����Ĵ�ֻ�ܶ࣬���ǲ�û�д���������ͣ����Ҫ���԰�ֻ�п�
���½��Լ��Ĵ�ֻ�ˡ�
LONG );
    set("exits", ([
        "westup" : __DIR__"shandao1",
    ]));
    set("item_desc", ([
        "he" : "һҶС�۾�ɭɭ�ؿ���«έ�ϣ���(yell)һ���Կ���\n",
    ]));
    set("objects", ([
        __DIR__"npc/huangboliu" : 1,
        __DIR__"npc/heiyiren" : 2,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "heimuya");
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
        if( !(room = find_object(__DIR__"duchuan1")) )
            room = load_object(__DIR__"duchuan1");
        if( room = find_object(__DIR__"duchuan1") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan1");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���÷��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "������̤�Ű��������������һ�㣬��������г�ȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan1") )
    {
        room->delete("exits/out");
        message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n���г�ȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan1") )
    {
        room->set("exits/out", __DIR__"xingxingtan");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan1") ) {
        room->delete("exits/out");
        message("vision","������̤�Ű����������ѱ��۳���ӽ�����\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
//    string dir;

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
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan1") )
        room->delete("yell_trigger"); 
}
