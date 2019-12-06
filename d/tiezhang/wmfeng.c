// Room: /u/zqb/tiezhang/mmfeng.c
#include <ansi.h>

inherit ROOM;

void close_passage();
string look_bei();

void create()
{
    set("short", GRN"������"NOR);
	set("long", @LONG
    ���·�ϵľ����ͻĲݣ������ڵ�����������ķ嶥���������� 
�ش����֮�У�����������ɽ���赲����˷��ƺ�С������������һƬ����
֮�С��嶥�����������ĻĲݣ���ʯ��ᾣ�һƬ������ɫ���ڷ嶥�����У�
��Ȼ������һ����ʯ���͵ķ�Ĺ����Ĺ��ǰ������һ��һ�˶�ߵĻ����ҵ� 
Ĺ��(bei)��
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"hclu-4",
]));

    set("item_desc",([
    "bei"         :       (: look_bei :),
    ]));
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");
	setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
  object me;
  me=this_player();

 if ((int)this_player()->query_temp("marks/��1")) 
{

      if ( (int)me->query_str() < 30)
        return notify_fail("��������������޷���ʯ���ƿ���\n");

 if (arg !="bei") 
  return notify_fail("��Ҫ��ʲô����\n");
    write("������������������˿�������Ĺ�������������ƿ���\n");
  message("vision",me->name() + "˫����������Ĺ�����Ի����ƿ�������¶��һ���ڶ�������ڡ�\n",    
            environment(me), ({me}) );
    set("exits/enter", __DIR__"shijie-1");
    remove_call_out("close_passage");
    call_out("close_passage", 10);
    return 1;
}
    return notify_fail("���в�ѽ��û����Ĺ����ʲô����\n");
}

void close_passage()
{
//    object room;

    if( !query("exits/enter") ) return;
    message("vision", "Ĺ������¡¡�������������ƻ�ԭ����\n", this_object() );
    delete("exits/enter");
}

string look_bei()
{
    return
    "\n"
 "*****************\n"
 "*           ��  *\n"
 "*           ��  *\n"
 "*           ��  *\n"
 "*       ��  ��  *\n"
 "*           ʮ  *\n"
 "*       ��  ��  *\n"
 "*           ��  *\n"
 "*       ��  ��  *\n"
 "*           ��  *\n"
 "*   ��  ��      *\n"
 "*   Ф          *\n"
 "*   ��          *\n"
 "*   ��  ֮      *\n"
 "*   ��  Ĺ      *\n"
 "*   ǧ          *\n"
 "*   ��          *\n"
 "*   ��          *\n"
 "*   ��          *\n"
 "*****************\n";
    "\n";
}

