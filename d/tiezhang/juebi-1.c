// Room: /u/zqb/tiezhang/juebi-1.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
    ���ߵ��������ǰ���Ѿ�û��·�ˡ�����ǰ��һ��������ɽ�� 
���������ƣ���������ͷ��ʯ���������źܶ����������紵����ɳɳ���졣 
�������Ϸ嶥��ֻ������ȥ�ˡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shangu-2",
]));
	set("no_clean_up", 0);
    set("outdoors", "tiezhang");
	setup();
}

void init()
{
        add_action("do_zhua","zhua");
        add_action("do_climb","climb");
}

int do_zhua(string arg)
{
        object me;
        me=this_player();
    
        if (arg =="����"){
                 write("�����ε�ץסʯ���ϵ�������\n");
        this_player()->set_temp("marks/ץ1", 1);
        return 1;
        }
        return notify_fail("��Ҫץʲô��\n");
}

int do_climb(string arg)
{       mapping fam;
        object me;
        me=this_player();
        
    if ( (int)me->query_skill("dodge", 1) < 30)
            return notify_fail("����Ṧ�������޷�����ȥ��\n");
    
    

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "���ư�")
        return notify_fail("��Ǳ�����ӣ������Ϸ壡\n");

    
    if (!me->query_temp("marks/ץ1") )
       
     return notify_fail("�޴���Ե������������ȥ��\n");
    if (arg =="up")
    {
        write("�����˿�����С�ĵ�������ȥ��\n");
        message("vision",me->name() + "����һ��ͻȻ�����ˡ�\n",
                environment(me), ({me}) );
        me->move(__DIR__"juebi-2");
        message("vision", me->name() + "����������\n",
        environment(me), ({me}) );
        this_player()->delete_temp("marks/ץ1");

     if ((int)me->query_skill("dodge",1)>100)
        write("����ú��Ѵ��������Ṧ����\n");

        me->receive_damage("qi", 40);
        me->improve_skill("dodge",me->query("int"));
     return 1;
    }
    return notify_fail("��Ҫ���Ķ�����\n");
}

