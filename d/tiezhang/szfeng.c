// Room: /u/zqb/tiezhang/szfeng.c

inherit ROOM;

void create()
{
	set("short", "ʳָ��");
	set("long", @LONG
    �����������˷嶥���Ѿ��۵����������ˡ�����ֻ������Բ��
�ط�����ݲ������������ǹ�ͺͺ����ʯ���������š�һ�����Х������
������һ�����򣬲��ˤ�����������ǸϿ��뿪����ĺá�
LONG	);
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");
	setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();

    me->receive_damage("qi", 40);
    if ((int)me->query_skill("dodge",1)<100)
    me->improve_skill("dodge",me->query("int"));

    if (arg =="down") 
    {
    write("����Ե��ʯ�ڣ�����������ȥ��\n");
    message("vision",me->name() + "������ȥ��\n",
            environment(me), ({me}) );
    me->move(__DIR__"juebi-5");
    message("vision",me->name() + "����������\n",   
            environment(me), ({me}) );
    }
    return 1;
}

