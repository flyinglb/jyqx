//   xuetong.c
//  by victori
inherit NPC;
void create()
{
        set_name("Сѧͯ", ({ "xue tong","tong" }) );
        set("gender", "����" );
        set("age", 14);
	set("per", 30);
        set("long", "����һ��ʮ�������Сͯ�����Ĳ����ɵĸ��������������ţ�\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
//      set("env/wimpy", 60);
	set_skill("dodge", 5);
	set_skill("unarmed", 5);
	set_skill("parry", 5);
	set("max_qi", 200);

  	set("chat_chance",10);
  	set("chat_msg",({
        "ֻ��Сѧͯ�϶��������������֮��...zzzz���Ա�....zzzzz��..~~~~��\n",
        "Сѧͯҡͷ���Եĸ�������������𣚣�ں����ޣ������㣬���Ӹ��ϡ�\n",
	"Сѧͯ���������������������������������������������������\n",
	"Сѧͯ�������͵������߲�����������˯����,.....��\n",
 //       (:random_move:)
    	}));
        setup();
        add_money("coin", 50);
set("inquiry", ([
//        "name": "��Ҷ����Ұ�ţ��ƽ����ɽ�����ʱҲ��Щҩ�ģ�\n",
//        "here": "���������ڣ���˵ɽ����λ����������\n",
]) );
       carry_object("/d/city/obj/cloth")->wear();
}
