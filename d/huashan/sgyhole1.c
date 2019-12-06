// sgyhole1.c
// By Hop, 97.04.30
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ�����п������Ĵ�ʯ����֪�����ж��ٻ�ɽ�ɵ�ǰ���ڴ�˼����
�ڣ���������ʯ�������û��ʯ��(wall)�����š������������
�֣������������̣��ʻ��Ծ������а�硣�����̵ֿþ����Ƿ��������
���书һ��ʮ���˵á�
LONG );
        set("objects", ([
//         CLASS_D("huashan")+"/linghu" : 1,
            "/d/heimuya/npc/linghu" : 1,
//         __DIR__"npc/ling-huchong.c" : 1,
        ]));
        set("exits", ([ /* sizeof() == 2 */
            "out" : __DIR__"siguoya",
        ]));
        set("item_desc", ([
            "wall" : "һ��ܺ��ʯ�ڡ�\n"
        ]) );
//        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
}
int do_break(string arg)
{
//    int n;
    object weapon,me=this_player();
    mapping fam;

    if ((fam = me->query("family")) && (fam["family_name"] != "��ɽ��")
       || !arg || arg!="wall" ) return notify_fail("���Ǹ��\n");
    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
       return notify_fail("��һ�ƴ���ʯ�ڣ����ֶ�����Ѫ��\n");

    message_vision(HIC
"$N�ߵ�ʯ��ǰ���γ����������������˾���ʯ�ڴ��˹�ȥ��\n"NOR,me);

    if (me->query("neili") < 200)
    {
       message_vision(HIC
"���ֻ��һ���ƺߣ�$N��ʯ�ڵķ����������ǰһ��....\n"NOR,me);
       me->set("neili",0);
       me->unconcious();
       return 1;
    }
    message_vision(HIC
"$Nֻ��һ�����죬ʯ�ڱ�ͱ���ˣ�ԭ��������һ���󶴡���\n"NOR,me);
    set("exits/enter",__DIR__"sgyhole");
    me->add("neili",-200);
    remove_call_out("close");
    call_out("close", 5, this_object());
//    remove_call_out("close_out");
//    call_out("close_out", 3);
    return 1;
}
void close_out()
{
    if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
    message("vision","���Ϻ�Ȼ������һ���ʯ�������ڷ��˸�����ʵʵ��\n", room);
    room->delete("exits/enter");
}
