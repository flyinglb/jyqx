//Room: xuanyuegate.c ������
//Date: Sep 22 1997

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short","������");
      set("long",@LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�һ������������¥ʽ��ʯ����ɽ��������
�����С������������ĸ����֣�ԭ������������������䵱ɽ���䵱ɽһ��
̫��ɽ��Ϊ��ʮ������֮һ���ж�ʮ�߷塢��ʮ���ҡ���ʮ�Ľ�����̨����
������̶�������š��������һ���أ�����������ɭ�ޣ����ղ��죬������
����
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/zhike": 1,
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"slxl3",
          "southup"  : __DIR__"shijie1",
      ]));
//      set("no_clean_up", 0);
      setup();
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("in_guard") &&
                objectp(present("zhike daozhang", environment(me))))
           return notify_fail("֪�͵�����ס��˵��ֵ��ʱ��δ������������ְ�ء�\n");

        me->delete_temp("in_guard"); 
        me->delete("guard");
        me->set("title", this_object()->query("title_temp"));
        me->delete("title_temp");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}
