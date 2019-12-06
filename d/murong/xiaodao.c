// /u/beyond/mr/xiaodao.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>

#define SHIP_TO __DIR__"matou"

inherit ROOM;  

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
         set("short",HIB"С����"NOR);
         set("long",@long
��һ���ϰ�ȥ, ��������������������, ������һ����֪����С�����
���ϡ�������ľ���̣�ͤ����鿴������ȣ�����Ʈ��һ�����㡣�����һ��
��һ��͸������ˮ��ɽ�壬����С�ɱ��µ���ɫ��һλ���������ڰ���(bian)��
long);
         set("exits", ([
             "south" : __DIR__"xiaoshe",
]));                                                                 
         set("item_desc",([
         "bian" : "����������(yell)һ�£����ͻ������̫����\n"
         ]));
         setup();
//       replace_program(ROOM);
}
                                               
void init()
{
    add_action("do_yell", "yell");
}
void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"zhou1-0")) )
            room = load_object(__DIR__"zhou1-0");
        if( room = find_object(__DIR__"zhou1-0") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"zhou1-0");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );

                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ú��治Զ�����������������"
                  "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻС���ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "������̤�Ű��������������һ�㣬���������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"zhou1-0") )
    {
        room->delete("exits/out");
       message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n����ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"zhou1-0") )
    {
        room->set("exits/out", __DIR__"matou");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room, *ob;
	int i;

    if( room = find_object(__DIR__"zhou1-0") ) {
		tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "������$Ņ���˴���\n", ob[i]);
				else tell_room(room, "$N���������Ļ����ԹԵ����˴����\n", ob[i]);
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
			}
		}
        room->delete("exits/out");
        message("vision","������̤�Ű����������ѱ���ʻ����С�\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
        object me = this_player();

	if (!arg) return 0;

	if (arg == "boat") arg = "����";
	if (me->query("age") < 16 )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);
	if( arg=="����")
	{
		check_trigger();
		return 1;
	}
	else {
		message_vision("������ԶԶ����һ���������" + arg + "��������\n", me);
		message_vision("��Ȼ��շ���һ�ţ���$N����һ����ͷ��һ���������ȵ������˴���ֹ��������\n", me);
	}
	return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"zhou1-0") )
        room->delete("yell_trigger"); 
}


