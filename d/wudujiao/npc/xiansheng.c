// xiansheng.c
inherit NPC;
void create()
{
        set_name("��������", ({ "xian sheng","xian" }) );
        set("gender", "����" );
        set("age", 40);
	set("per", 30);
        set("long", "һλ���������������ʿ����ҡͷ���Ե��ڽ�ѧ�����飮\n");

        set("combat_exp", 1000);
        set("attitude", "friendly");
//      set("env/wimpy", 60);
	set_skill("dodge", 15);
	set_skill("unarmed", 10);
	set_skill("parry", 15);
	set("max_qi", 400);

  	set("chat_chance",10);
  	set("chat_msg",({
        "ֻ�����������������֮�����Ա��ƣ�......��\n",
        "��������ҡͷ���Ե��������ع���𣚣�ں�֮�ޣ�����Ů�����Ӻ��ϡ�\n",
	"������������������������������������ӣ����Ӳ������������ӡ�\n",
	"��������������������߲�����������������,.....��\n",
 //       (:random_move:)
    	}));
        setup();
        add_money("silver", 5);
set("inquiry", ([
//        "name": "��Ҷ����Ұ�ţ��ƽ����ɽ�����ʱҲ��Щҩ�ģ�\n",
//        "here": "���������ڣ���˵ɽ����λ����������\n",
]) );
       carry_object("/d/city/obj/cloth")->wear();
}
