// by mayue

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������嶾�̵���ר�ŵ������ң��������������Ƹ��ֶ�ҩ�����ϰ�
�Ÿ�ʽ���������ߡ��������з���һ��һ�˶�ߵĵ�¯��¯����������һ
�����ݵĵ������ֳ���ľ����¯���ߣ������������ﲻ֪����Щʲô��
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"yaoshi",
//		"south" : __DIR__"liandu ",
//		"west" : __DIR__"nanyuan",
		"north" : __DIR__"nanyuan",
	]));
        set("objects", ([
                __DIR__"npc/daoren": 1,
	]));
	setup();
//	replace_program(ROOM);
}

void init ()
{
  add_action("do_lianzhi","lianzhi");
}

int do_lianzhi (string arg)
{
    object ob;
    object me = this_player();
    if (arg != "red yao"&& arg!="yellow yao" && arg!="green yao"
        && arg!="white yao"&& arg!="black yao" && arg!="shenxiandao")
    return 0;
    if (arg == "red yao"){
         if (!present("she dunang",me)||!present("shexin zi",me))
              return notify_fail("������ҩƷ��ȫ���޷����ơ�\n");
         destruct(present("she dunang",me));
         destruct(present("shexin zi",me));
         ob = new(__DIR__"obj/redyao");
         ob->move(me);
         message_vision ("$N�����ϵ�ҩƷͶ�뵤¯�����ط�С������������\n",me);
	  tell_object(me, "ҩƷ���Ƴɹ���\n");
     }
    if (arg == "yellow yao"){
         if (!present("wugong dunang",me)||!present("chuanxin lian",me))
              return notify_fail("������ҩƷ��ȫ���޷����ơ�\n");
         destruct(present("wugong dunang",me));
         destruct(present("chuanxin lian",me));
         ob = new(__DIR__"obj/yellowyao");
         ob->move(me);
         message_vision ("$N�����ϵ�ҩƷͶ�뵤¯�����ط�С������������\n",me);
	  tell_object(me, "ҩƷ���Ƴɹ���\n");
     }
    if (arg == "green yao"){
         if (!present("zhizhu dunang",me)||!present("fugu cao",me))
              return notify_fail("������ҩƷ��ȫ���޷����ơ�\n");
         destruct(present("zhizhu dunang",me));
         destruct(present("fugu cao",me));
         ob = new(__DIR__"obj/greenyao");
         ob->move(me);
         message_vision ("$N�����ϵ�ҩƷͶ�뵤¯�����ط�С������������\n",me);
	  tell_object(me, "ҩƷ���Ƴɹ���\n");
     }
    if (arg == "white yao"){
         if (!present("xiezi dunang",me)||!present("heding hong",me))
              return notify_fail("������ҩƷ��ȫ���޷����ơ�\n");
         destruct(present("xiezi dunang",me));
         destruct(present("heding hong",me));
         ob = new(__DIR__"obj/whiteyao");
         ob->move(me);
         message_vision ("$N�����ϵ�ҩƷͶ�뵤¯�����ط�С������������\n",me);
	  tell_object(me, "ҩƷ���Ƴɹ���\n");
     }
    if (arg == "black yao"){
         if (!present("chanchu dunang",me)||!present("duanchang cao",me))
              return notify_fail("������ҩƷ��ȫ���޷����ơ�\n");
         destruct(present("chanchu dunang",me));
         destruct(present("duanchang cao",me));
         ob = new(__DIR__"obj/blackyao");
         ob->move(me);
         message_vision ("$N�����ϵ�ҩƷͶ�뵤¯�����ط�С������������\n",me);
	  tell_object(me, "ҩƷ���Ƴɹ���\n");
     }
    if (arg == "shenxiandao"){
         if (!present("jinshe duye",me)||!present("qianri zui",me))
              return notify_fail("������ҩƷ��ȫ���޷����ơ�\n");
         destruct(present("jinshe duye",me));
         destruct(present("qianri zui",me));
         ob = new(__DIR__"obj/shenxiandao");
         ob->move(me);
         message_vision ("$N�����ϵ�ҩƷͶ�뵤¯�����ط�С������������\n",me);
	  tell_object(me, "ҩƷ���Ƴɹ���\n");
     }
 return 1;
}











