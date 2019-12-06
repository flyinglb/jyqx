// by mayue

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
����һ����������᷿�����浽�����Ǹ��ִ��СС�����ӡ��߹�֮
��Ķ�������ʱ�ܿ����ж��������������ϴ��������Ĵ����ߡ�һ������
���ӵİ׺�������������æ���ҵĸ������ǰ���ιʳ��æ����æ���ҡ�
LONG
	);
	set("exits", ([
		"east" : __DIR__"nanyuan",
//		"south" : __DIR__"liandu ",
//		"west" : __DIR__"nanyuan",
//		"north" : __DIR__"nanyuan",
	]));
        set("objects", ([
                __DIR__"npc/oldman": 1,
                __DIR__"obj/zhulou": 3,
	]));
	setup();
//	replace_program(ROOM);
}

void init ()
{
  add_action("do_cun","cun");
  add_action("do_qu","qu");
}

int do_cun (string arg)
{
    object ob;
    int du_exp,du_attack,du_defense,du_dodge,du_armor,du_qi,du_jing;
     int du_age;
    string du_name,du_id;
    object me = this_player();
    if ((string)me->query("family/family_name")!="�嶾��"
        || !objectp(present("old man", environment(me))))
          return notify_fail("ʲô��\n");
    if (!arg)  return notify_fail("��Ҫ�Ĵ�ʲô��\n");
    ob = present(arg,environment(me));
    if (!objectp(ob))  return notify_fail("��Ҫ�Ĵ�ʲô��\n");
    if (ob->query("host_id") != me->query("id"))
         return notify_fail("������ˣ��ǿɲ�����Ķ��档\n");
    if (ob->query("age") < 99 )
         return notify_fail("������ˣ��ǿɲ�����Ķ��档\n");
    if (me->query("duchong_cun") > 0 )
         return notify_fail("�������߰���һ�ɣ��������ĵ������Ѿ�����һ�������ˣ��������Ұ���\n");
         message_vision ("��������Ц�����ðɣ��ҾͰ����տ�һ��ʱ�䣬����İɡ�\n",me);
     me->set("duchong_cun",1);
     du_exp=ob->query("combat_exp");
     du_attack=ob->query_temp("apply/attack");
     du_defense=ob->query_temp("apply/defense");
     du_armor=ob->query_temp("apply/armor");
     du_dodge=ob->query_skill("dodge",1);
     du_qi=ob->query("max_qi");
     du_jing=ob->query("max_jing");
     du_name=ob->query("name");
     du_id = ob->query("id");
     me->set("du_exp",du_exp);
     me->set("du_attack",du_attack);
     me->set("du_defense",du_defense);
     me->set("du_armor",du_armor);
     me->set("du_dodge",du_dodge);
     me->set("du_qi",du_qi);
     me->set("du_jing",du_jing);
     me->set("du_name",du_name);
     me->set("du_id",du_id);
     du_age=ob->query("age");
     if(du_age > 99 && du_age < 999) me->set("du_age",100);
     if(du_age > 999 && du_age < 9999) me->set("du_age",1000);
     if(du_age > 9999 ) me->set("du_age",10000);
     message_vision ("��������һ�ѽ�"+du_name+"ץ�������������Աߵ������\n",me);
      destruct(ob);
      me->save();
 return 1;
}
int do_qu (string arg)
{
    int du_exp,du_attack,du_defense,du_dodge,du_armor,du_qi,du_jing;
    object ob;
   int du_age;
    string du_name,du_id;
    object me = this_player();
    if ((string)me->query("family/family_name")!="�嶾��"
        || !objectp(present("old man", environment(me))))
          return notify_fail("ʲô��\n");
    if (present("wudu ling",me)){
             me->set("duchong_cun",1);
             message_vision ("�������߿�Ц�������������嶾�������û�У���ҲҪ��������һ����\n",me);
             destruct(present("wudu ling",me));
     }        
    if (me->query("duchong_cun") < 1 )
         return notify_fail("�������߰���һ�ɣ��������ĵ�����ʲôʱ���������������\n");
     message_vision ("��������Ц������������߰ɣ����ʱ�����������ˡ�\n",me);
     me->set("duchong_cun",0);
     du_exp=me->query("du_exp");
     du_attack=me->query("du_attack");
     du_defense=me->query("du_defense");
     du_armor=me->query("du_armor");
     du_dodge=me->query("du_dodge");
     du_qi=me->query("du_qi");
     du_jing=me->query("du_jing");
     du_name=(string)me->query("du_name");
     du_id =(string)me->query("du_id");
     du_age=me->query("du_age");
     if(du_age> 99 && du_age < 999 && du_id=="du she"){
         ob =new(__DIR__"npc/she1");
     }
     if(du_age> 999 && du_age < 9999 && du_id=="du she"){
         ob =new(__DIR__"npc/she2");
     }
     if(du_age> 9999 && du_id=="du she"){
         ob =new(__DIR__"npc/she3");
     }
     if(du_age> 99 && du_age < 999 && du_id=="zhi zhu"){
         ob =new(__DIR__"npc/zhizhu1");
     }
     if(du_age> 999 && du_age < 9999 && du_id=="zhi zhu"){
         ob =new(__DIR__"npc/zhizhu2");
     }
     if(du_age> 9999 && du_id=="zhi zhu"){
         ob =new(__DIR__"npc/zhizhu3");
     }
     if(du_age> 99 && du_age < 999 && du_id=="wu gong"){
         ob =new(__DIR__"npc/wugong1");
     }
     if(du_age> 999 && du_age < 9999 && du_id=="wu gong"){
         ob =new(__DIR__"npc/wugong2");
     }
     if(du_age> 9999 && du_id=="wu gong"){
         ob =new(__DIR__"npc/wugong3");
     }
     if(du_age> 99 && du_age < 999 && du_id=="xie zi"){
         ob =new(__DIR__"npc/xiezi1");
     }
     if(du_age> 999 && du_age < 9999 && du_id=="xie zi"){
         ob =new(__DIR__"npc/xiezi2");
     }
     if(du_age> 9999 && du_id=="xie zi"){
         ob =new(__DIR__"npc/xiezi3");
     }
     if(du_age> 99 && du_age < 999 && du_id=="chan chu"){
         ob =new(__DIR__"npc/chanchu1");
     }
     if(du_age> 999 && du_age < 9999 && du_id=="chan chu"){
         ob =new(__DIR__"npc/chanchu2");
     }
     if(du_age> 9999 && du_id=="chan chu"){
         ob =new(__DIR__"npc/chanchu3");
     }
     ob ->move(environment(me));
     ob->set("combat_exp",du_exp);
     ob->set_temp("apply/attack",du_attack);
     ob->set_temp("apply/defense",du_defense);
     ob->set_temp("apply/armor",du_armor);
     ob->set_skill("dodge",du_dodge);
     ob->set("max_qi",du_qi);
     ob->set("max_jing",du_jing);
     ob->set("name",du_name);
     ob->set("eff_jing",   ob->query("max_jing"));
     ob->set("jing",   ob->query("max_jing"));
     ob->set("eff_qi",   ob->query("max_qi"));
     ob->set("qi",   ob->query("max_qi"));
     ob->set("food",    ob->max_food_capacity());
     ob->set("water",    ob->max_water_capacity());
     message_vision ("�������ߴ��Ա�ȡ��һ�����ӣ������š�"
                     +du_name+"��ʱ��������˳�����\n",me);
     ob->set("host_id",(string)me->query("id"));
     ob->set_leader(me);
      me->save();
 return 1;
}











