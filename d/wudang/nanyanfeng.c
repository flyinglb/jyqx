//Room: nanyanfeng.c ���ҷ�
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���ҷ�");
      set("long",@LONG
�������䵱��ʮ����֮��������죬ľʯ���棬�ͱ�����������
֮������һ���������Ԩ�����̺ƴ󡣹�ǰ��һʯ�������ͱ��Ϻ����
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/mo": 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
          "eastdown" : __DIR__"langmeiyuan",
          "southdown": __DIR__"shizhu",
          "west"     : __DIR__"sheshenya",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "�䵱��") && dir == "southdown" &&
                objectp(present("mo shenggu", environment(me))))
           return notify_fail("Ī������ס��˵���˴��˱��ɽ��أ���ֹ����\n");

        return ::valid_leave(me, dir);
}
