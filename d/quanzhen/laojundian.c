// laojundian.c �Ͼ���
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ͼ���");
        set("long", @LONG
�����ǹ���̫���Ͼ��Ĵ�������������Ͼ��������Ͼ���
����ţ�ϣ������ƶ�ȥ��������������ͯ�ӣ����������������еĵ�
��������שһ�����̳ɣ���ɨ��һ����Ⱦ��
LONG
        );
        set("exits", ([
                "east" : __DIR__"houtang1",
                "south" : __DIR__"tongtiandian",
                "north" : __DIR__"yuanshidian",
                "west" : __DIR__"datang3",
        ]));
        set("objects", ([
                __DIR__"npc/qiu" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "east" )
        {
                if(!(fam = me->query("family")) || fam["family_name"] != "ȫ���") {
                        if(present("qiu chuji", environment(me)) && living(present("qiu chuji", environment(me))))
                        {
                                return notify_fail(
"�𴦻��ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}
