// by mayue


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ʯ�ң����������ҳ��������ж���û�˴�ɨ��
�ġ�����ֻ��һ��һ����һ������Ӷ������ҷ������룬���ڹ�����
����ǽ����һ����ʯ��(bed)�����Ա�ʯ�ڵ�ɫ���кܴ�ͬ��͸��
б������⣬�㿴��ʯ������ǽ�����ƺ�����һЩ���ֺ�ͼ�Ρ�һ��
����ʯ���ϰ���һ��ʯϻ(xia)��
LONG
	);
//      set("outdoors", "wudujiao");
        set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
		"eastup" : __DIR__"shixi",
//            "down" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
//		"north" : __DIR__"wandu2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
       set("item_desc",([
         "wall":"\n       ֻ��ʯ���Ͽ��š�ǧ���򶾡��ĸ����ɷ���Ĵ��֡�\n
       ������������ϥ���������񣬿̵�����������ÿ�������ƶ�����ͬ��\n
       �Ա߻������С��,�㲻��������ϰ(lianxi)һ�¡�\n ",
         "ǽ��":"\n       ֻ��ʯ���Ͽ��š�ǧ���򶾡��ĸ����ɷ���Ĵ��֡�\n
       ������������ϥ���������񣬿̵�����������ÿ�������ƶ�����ͬ��\n
       �Ա߻������С�֣��㲻��������ϰ(lianxi)һ�¡�\n ",
         "bed":"\nһ������ͨͨ��ʯ����\n ",
         "xia":"\nһֻʯϻ�������Ǻ�ʯ������һ��ģ���֪���Ҳ��Ҵ򿪿�����\n ",
]));
       set("mishi_book",1);
	setup();
//	replace_program(ROOM);
}
void init()
{
  add_action("do_lianxi", "lianxi");
  add_action("do_jump", "jump");
  add_action("do_open", "open");
}

int do_lianxi(string arg)
{
//  object weapon;
  object me=this_player();
  int forceskill=(int)me->query_skill("force", 1);
  int wuduskill=(int)me->query_skill("wudu-shengong", 1);
//  int maxlevel, exp=(int)me->query("combat_exp");
  int exp=(int)me->query("combat_exp");
  if( me->query("jing") < (int)(me->query("max_jing")/5))
    return notify_fail("���Ѿ�û�о�����ϰ�ˣ�\n");
  if (!((string)me->query("family/family_name")=="�嶾��")
     || !(int)me->query_temp("wudu_onbed"))
    {
      message_vision("$N��ϥ���������ű��ϵ�ͼ�����˼��Σ�ֻ����һ��ڸ����\n", me);
    }
  else
    {
      message_vision("$N���ű���ͼ�ε�������ϥ���£��ܿ�;���������\n", me);
      if (exp*10 <= (wuduskill*wuduskill*wuduskill))
	{
	  me->receive_damage("qi", 30);
	  return notify_fail("������ľ��鲻����ʼ�ղ��ܴ�ͼ������ʲô��\n");
	}
      if (wuduskill >150 && forceskill>150 )
	{
	  me->improve_skill("wudu-shengong", 2*(int)(me->query("int")
                          +me->query_skill("literate")));
	  tell_object(me, "���ƺ����������һЩ�嶾�񹦷�������š�\n");
	}
      else
	{
	  tell_object(me, "��Ĺ���̫���ˣ����������ͼ�����ص��������š�\n");
	}
    }
  me->receive_damage("jing", 20);
  return 1;
}
int do_jump(string arg)
{
  object me=this_player();
  if( !arg ||! (arg =="bed" || arg =="up" || arg =="down"))
       return 0;
  if( arg =="up"||arg=="bed"){
       if ((int)me->query_temp("wudu_onbed") )
              return notify_fail("���Ѿ��ڴ����ˣ����������������ˡ�\n");
       me->set_temp("wudu_onbed",1);
       message_vision("$P����һ��������ʯ��������������\n", me);
	tell_object(me, "��ֻ����һ˿˿���������´������پ�����һ��\n");
   }      
  if( arg =="down"){
       if (!(int)me->query_temp("wudu_onbed") )
              return notify_fail("���Ѿ��ڵ����ˣ��ұ������ɺ���ͳ��\n");
       me->delete_temp("wudu_onbed");
       message_vision("$P��ʯ��������������\n", me);
   }      
  return 1;
}
int valid_leave (object me, string dir)
{
  if (me->query_temp("wudu_onbed"))
      	 return notify_fail("���´����ߣ�����·Ҳ������\n");
  return 1;
}
int do_open(string arg)
{
  object me,ob;
  me=this_player();
  if( !arg || arg !="xia")
       return 0;
  if( query("mishi_book") < 1)
              return notify_fail("���ʯϻ����������տ���Ҳ��\n");
  add("mishi_book", -1);
  message_vision("$P��ʯϻ��������ȡ��һ����ᡣ\n", me);
  ob = new(__DIR__"obj/dujing2");
  ob->move(me);
  return 1;
}
