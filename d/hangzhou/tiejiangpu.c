// tiejiangpu.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ�Ҳ�С�Ĵ����̣�������˼�����¯��һλ�������ڻ�¯
����ͷ�󺹵ش��춫����һλ�������ڱ��ϡ���¯�߷��Ų��ٴ����
��������
LONG);
///    �ſڹ���һ������(paizi)��
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"road11",
        ]));
        set("item_desc", ([
            "cannotsawpaizi" :
"��Ҫ'����'������ŷұʦ����\n"
"���������ı����Ͽ��´�ɫ���֣������ڱ�����\n"
"ǰ�����$XXX$���ڱ�������ǵûָ�Ϊ$NOR$��\n"
"$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ\n"
"$RED$ - ��ɫ            $HIR$ - ����ɫ\n"
"$GRN$ - ��ɫ            $HIG$ - ����ɫ\n"
"$YEL$ - ����ɫ          $HIY$ - ��ɫ\n"
"$BLU$ - ����ɫ          $HIB$ - ��ɫ\n"
"$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ\n"
"$CYN$ - ����ɫ          $HIC$ - ����ɫ\n"
"$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ\n",
        ]));
        set("objects", ([ /* sizeof() == 1 */
//            __DIR__"npc/ouyezi" : 1,
            __DIR__"npc/smith" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        me=this_player();
        if (dir == "west")
        if((int)me->query_temp("marks/ouyezi"))
        {
           return notify_fail("�����������������λ�͹٣����˱������ߣ�\n");
        }
        return 1;
}
