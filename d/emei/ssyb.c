//Room: ssyb.c �����±�
//Date: Oct. 21 1997 by That

inherit ROOM;
void create()
{
      set("short","�����±�");
      set("long",@LONG
�������ε��±ڡ�̧ͷ������΢����⡣���泱ʪ���ѷ���΢��ˮ��
�������������ǵĳ�ˮ�����ܵľ��ﶼ�����塣�򶫾�������ʱ��ˮ̶��
LONG);
      set("outdoors","emei");
      set("objects", ([
          __DIR__"npc/frog" : 1,
      ]) );
      set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"st8", 
      ]));
      set("no_clean_up", 0);
      set("no_fight",1);
      setup();
}
void init()
{
    add_action("do_dig","dig");
    add_action("do_climb","climb");
}
int do_climb()
{
    object me;
    me = this_player();
    message("vision", me->name()+"ʹ������ȥ�����˾�ţ����֮����\n", environment(me), ({me}) );
    me->move(__DIR__"gudelin1");
    message("vision", me->name()+"���˾�ţ����֮������������ط���ȴ��֪�������\n", environment(me), ({me}) );
    return 1;
}
int do_dig()
{
    object ob,me;
    me = this_player();
/*
    if (me->query("marks/���콣") || me->query("max_naili")<500)
    {
       message_vision("����ʲôҲû���ˣ�$N����̾�˿�����\n",me);
       return 1;
    }
*/
    if (me->query("marks/skysword") )
    {
//       if ((random(10))==3)
       if (me->query("id")=="robin")
       {
          message_vision("$N��Ȼ�ڵ���Ӳ�Ķ�����������Ĩ�������������˵Ĵ�Ц������\n", me);
          write("������������콣����\n");
          me->set("marks/���콣",1);
          ob = new(__DIR__"obj/skysword");
          ob->move(me);
       }
       else
       {
          me->add("qi",-20);
          message_vision("$Nʹ����ʯ�����ڣ��ֶ��ڳ�Ѫ�ˡ����ǰ�æ�ˡ�\n", me);
          me->set("marks/���콣",1);
       }
       return 1;
    } 
}
