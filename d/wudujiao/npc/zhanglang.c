//   zhanglang.c
//  by victori
inherit NPC;
void create()
{
        set_name("���", ({ "zhang lang","lang" }) );
	 set("race", "Ұ��");
        set("age", 4);
	 set("per", 30);
        set("long", "һֻ���˶��ĵ�С���ӣ�������Ŀ����㡣\n");
        set("combat_exp", 60);
        set("attitude", "friendly");
//      set("env/wimpy", 60);
	set_skill("dodge", 5);
	set_skill("unarmed", 5);
	set_skill("parry", 5);
	set("max_qi", 100);

  	set("chat_chance",10);
  	set("chat_msg",({
        "ߴߴ...ߴߴߴߴ��....ߴߴߴ..~~~~��\n",
 //       (:random_move:)
    	}));
        setup();
//        add_money("coin", 50);
set("inquiry", ([
//        "name": "��Ҷ����Ұ�ţ��ƽ����ɽ�����ʱҲ��Щҩ�ģ�\n",
//        "here": "���������ڣ���˵ɽ����λ����������\n",
]) );
//       carry_object("/d/city/obj/cloth")->wear();
}
