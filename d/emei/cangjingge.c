//Room: cangjingge.c �ؾ���
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","�ؾ���");
      set("long",@LONG
С��¥�ϱ��Ƕ����ɵĲؾ����ˡ����ﶼ���������飬�߼��������ܡ�
��������һ�Ŵ����ӣ����Ϸ��˼����𾭡��и�Сʦ̫�����򾲵�ʦ̫���顣
LONG);
      set("objects", ([
           CLASS_D("emei") + "/dao" : 1,
           __DIR__"obj/fojing1"+random(2) : 1,
           __DIR__"obj/fojing2"+random(2) : 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
          "down"  : __DIR__"chuwujian", 
      ]));
//      set("no_clean_up", 0);
      setup();
}
int valid_leave(object me, string dir)
{
     me = this_player();
     if ((dir == "south") && ( present("shu", me))
          && objectp(present("jingdao", environment(me))))
     {
         return notify_fail
                ("����ʦ̫������Ѿ������ߣ���ǰ����˵���������鲻��衣\n");
     }
     return ::valid_leave(me, dir);
}
