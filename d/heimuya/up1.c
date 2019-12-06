// Room: carol/heimuya

inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_insert(string arg);

void create()
{
    set("short", "����ƺ");
    set("long", @TEXT
�����ǰ�ɽ��һƬС��ƺ�����¶�����һ��·;���ɵ�����
��û��·��ȥ����ǰ���羳����ͱڣ���ͷ�����������¶���ϡ
������¥�������ɾ������������ƣ������������������ϴ���
һ������(rope)������ȥ�����������»�ͨ��Ϣ�Ĺ��ߣ�������
�����ƺ���Լ��һ������(basket)�����µ�ǽ���ƺ���һ��ϻ��
(xiazi) �����ƺ�����һ����լ���治֪����Ǻá�
TEXT);

    set("exits", ([
	"eastdown" : __DIR__"shimen",
    ]));
    set("objects", ([
	__DIR__"npc/zhang1" : 1,
    ]));

    set("item_desc", ([
        "basket": "����һ����������������Щ�Ź֡�\n",
        "rope"  : "���Ӿ������ӣ����������ϵĹ��ߡ�\n",
        "xiazi" : "����һ��ϻ�ӣ���������һ�����أ�ϻ�ӵĲ�����һ����ס�\n",
    ]));
//    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_insert", "insert");
    
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"basket")) )
            room = load_object(__DIR__"basket");
        if( room = find_object(__DIR__"basket") ) {
            if((int)room->query("insert_trigger")==0 ) {
                room->set("insert_trigger", 1);
                set("exits/enter", __DIR__"basket");
                room->set("exits/out", __FILE__);
                message("vision", "ֻ��һ������(basket)����������㲻��һ����\n"
                    , this_object() );
                set("item_desc", ([
                    "basket" : "����һ���������Ǵ�˵�еĽ�ͨ���ߡ�\n",
                ]));
                
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "��������õ��²�����\n",this_object() );
        }
        else
            message("vision", "ERROR: basket not found\n", this_object() );
    }
}

void on_board()
{
    object room;
    if( !query("exits/enter") ) return;
    message("vision", "ֻ�������������ϣ������������ã�\n"
             "���ƺ�������һ���˼��ɾ����졣\n", this_object() );

    if( room = find_object(__DIR__"basket") )
    {
        room->delete("exits/out");
    }
    delete("exits/enter");
    remove_call_out("arrive");
    call_out("arrive",20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"basket") )
    {
        room->set("exits/out", __DIR__"up2");
        message("vision", "���һ�������ƺ�һ�´����ϵ��˵��ϡ�\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"basket") ) {
        room->delete("exits/out");

        room->delete("insert_trigger");
    }
}

int do_insert(string arg)
{
//    string dir;
    object ob;
    object me;

    me=this_player();

    if( !arg || arg=="" ) return 0;

    if( arg=="��" ) arg = "card1";   
    
    if( arg=="card1")
    {
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
        if( !me->query_temp("mark/cards") )
                me->set_temp("mark/cards",1);
        if( me->query_temp("mark/cards")==4)
        {
                check_trigger();
		me->delete_temp("mark/cards");
        }
        else    {
                me->add_temp("mark/cards",1);
                message("vision", "���һ�����㿴����������һ�ڡ�\n",me );
        }
    }
    return 1;
}
