//Room: cangjinglou.c �ؾ�¥
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","�ؾ�¥");
      set("long",@LONG
�����Ǳ����µĲؾ�¥����¥�������������˺ö���ܣ����ϰ����˾��顣
�����������µ�Сʦ̫����һ�Ǿ����ض��ž��顣
LONG);
      set("objects", ([
           CLASS_D("emei") + "/daoming" : 1,
           __DIR__"obj/fojing1"+random(2) : 1,
           __DIR__"obj/fojing2"+random(2) : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "south"    : __DIR__"dxdian",
      ]));
//      set("no_clean_up", 0);
      setup();
}

int valid_leave(object me, string dir)
{
     me = this_player();
     if ((dir == "south") && ( present("shu", me))
          && objectp(present("daoming", environment(me))))
     {
         return notify_fail
                ("����Сʦ��������Ѿ������ߣ���ǰ����˵���������鲻��衣\n");
     }
     return ::valid_leave(me, dir);
}
