// cuihua.c

inherit NPC;

void create()
{
	set_name("����",({ "cui lan", "lan" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "���Ǹ�����ͨͨ��ũ����Ů�����������ߵĵ�����ͷ��\n");

//      set("shen", -100);
        set("shen_type", 1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 200);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
  	set("chat_chance",10);
  	set("chat_msg",({
//     "�峤̾���������ĵ��������ڻ�û�������᲻�س��°���\n",
	"���������������������ô����������������Ҫ���ˡ�\n",
      	}));

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 150);
set("inquiry", ([
"����": "�ҵ������嶾ɽ��ҩȥ�ˣ���ô���ˣ�Ҳ�ûؼ��ˣ�\n",
"�嶾ɽ": "�嶾ɽ���ڴ��ӵĶ��ϱߣ�������ɽҪͨ���һ����������ҵ��������˲���ȥ�ģ�\n",
"�һ���": "����һ��������������궼������������������Ҳ������о�ɢ��\n",
"����о�ɢ": "ȫ����ҵ����������������˵�Ǹ�һ�������ʲô��Ҫ�ģ�\n",
]) );
}

