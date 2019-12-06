// by mayue


inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��Ѩ");
	set("long", @LONG
�����Ƕ��ڸߴ���һ��С��Ѩ���ط�С��ֻ������һ���˴���
����ڶ�����ʲôҲ��������ֻ�ж��Ե�һ�������С�ݣ�Ҷ����
˸�ŵ����׹⣬�Եù����쳣��
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
//            "down" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
//		"north" : __DIR__"wandu2",
	]));
        set("objects", ([
                  __DIR__"obj/duanchang": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}
void init ()
{
  add_action("do_fire","fire");
  add_action("do_insert","insert");
  add_action("do_climb","climb");
}

int do_fire (string arg)
{
  object me = this_player();
    if (arg != "ba" && arg!="huo ba")
    return 0;
    if (!present(arg,me))  return notify_fail("��Ҫ��ȼʲô��\n");
    message_vision ("$N���һ������һ֧��ѣ�\n\n",me);
    message_vision ("ɲ�Ǽ����ܱ��յ����������\n",me);
    this_object()->recreate();
//  message_vision ("\n������\n",me);
//  message_vision (this_object()->query("long"),me);
    me->set_temp("fire_huoba",1);
    remove_call_out ("precreate");
    call_out ("precreate",20,this_object());
    destruct(present(arg,me));
    return 1;
}

void precreate (object me)
{
    tell_room (me,"���ߺ���һ�������Ϩ���ˣ������ֱ��һƬ��ڣ�\n\n");
    me->delete_temp("fire_huoba");
    me->create();
//  destruct(present("huo ba",me));
}

int do_insert (string arg)
{
 object ob;
 object me = this_player();
     if ((int)me->query_temp("fire_huoba")< 1)
          return notify_fail("���ܺ�����ģ�ʲôҲ����������\n");
     if (arg != "tongpai")
          return 0;
     if (!present(arg,me))  return notify_fail("��Ҫ����ʲô��\n");
     if ((int)me->query_temp("fire_huoba")< 1)
          return notify_fail("���ܺ�����ģ�ʲôҲ����������\n");
     message_vision ("$N���Ž�ͭ�Ʋ���ʯ���ϵ�С���У�\n\n",me);
     message_vision (HIC"��Ȼһ��¡¡�ľ����𶯣�$Nֻ����һ��������ת��\n\n"NOR,me);
     destruct(present(arg,me));
     ob = load_object(__DIR__"mishi");
     ob = find_object(__DIR__"mishi");
     message("vision", me->query("name")+"��Ȼ���Ҷ���϶�л��˽�����\n", ob);
     message_vision ("$N��Ȼ���ý���һ�գ���������ȥ��\n\n",me);
     me->delete_temp("fire_huoba");
     me->move(__DIR__"mishi");
     return 1;

}
int do_climb(string arg)
{
       
	object me=this_player();
	object ob; 
	if( (!arg) ||!((arg == "�ұ�") || (arg == "����")))
		return notify_fail("��Ҫ��ʲô��\n");
		message_vision(HIC"$NС������������ұ���ͻ����ʯ��������ȥ��\n\n"NOR,me);
        ob = load_object(__DIR__"wandu3");
        ob = find_object(__DIR__"wandu3");
        message("vision", me->query("name")+"���ұ�������������\n", ob);
        me->move(__DIR__"wandu3");
        return 1;
}

void recreate ()
{
  set ("short", "��Ѩ");
  set ("long", @LONG
����һ����խ�Ķ�Ѩ������ʯ��ʪ�����ģ���������̦������ϸ
�۲�һ�����ܵ���������ֶ������һ��ʯ�ڷǳ�ƽ������������
���ĺۼ������м���һ������С�ף�������Բ���(insert)ʲô��
�����ԡ�
LONG);

  set("exits", ([
//        "down"  : __DIR__"wandu3",
      ]));
//  set("outdoors","wudujiao");

  setup();
}
