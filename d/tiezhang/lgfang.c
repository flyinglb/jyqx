//Room: /u/zqb/tiezhang/lgfang.c

// Date: YZC 96/01/19
#include <ansi.h>

inherit ROOM;
//void init();
//int do_chazhi();

void create()
{
        set("short",HIC"������"NOR);
	set("long", @LONG
    ����һ���û��������ɵ�ʯ�ݡ�����һֻ��¯��ȼ�˺�̿��������
�����ڵ�һ��(huo )������������������Сͯ��һ��ʹ���������䣬��һ��
��������������֮�����ɳɳ֮����������������ɳ���������е��ӱ�Ŀ
��ϥ���ڹ�ǰ����������ϵ��������ţ����ָ�����п�����
LONG
	);
        set("exits", ([ 
  "east" : __DIR__"guangchang",
]));

	set("objects",([
    __DIR__"npc/heiyi" : 1,
	]));

	set("item_desc", ([
    "huo" : "����һ�ھ޴������������ʢ����ɳ������ȼ��̿��\n",
	]));

	setup();
}

void init()
{
    add_action("do_chazhi", "chazhi");
}


int do_chazhi(string arg)
{       
        mapping fam;
	object me;
        me = this_player();

    if (!living(me)) return 0;
    if ( !living(this_player()) || arg != "huo" )
        {    write("�������Ķ���ѽ��\n");
        return 1;
        }

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "���ư�")
            return notify_fail("��Ǳ�����ӣ������ڴ�������\n");

    if ( (int)me->query_skill("strike", 1) > 100)
             return notify_fail("�㽫˫�ֲ������У�������ɳ���¶ȶ�����˵̫�ͣ��Ѻ��������ˡ�\n");
    
    if((int)me->query("qi")<30){
           me->receive_damage("qi",10);
           write("�����һ������ֱ�������������ѵ���\n");
           me->unconcious();
		return 1;
	}
    me->receive_damage("qi", random(40));
    me->improve_skill("strike", me->query("int"));
    message_vision("$N��˫�ֲ�����е���ɳ�\n", me);
    write("���ȵ���ɳ�����˫���̵�ͨ�죬�����˫�ֱ��ǿ׳������\n");
    return 1;
}

