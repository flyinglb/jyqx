// cunzhang.c

inherit NPC;

void create()
{
	set_name("������",({ "miao sanjin","miao"}) );
        set("gender", "����" );
        set("age", 58);
        set("long", "���Ǳ���Ĵ峤�����Ǵ�����Ҹ������������ٵ�����û�в�֪���ġ�\n");

        set("max_qi", 300);
        set("shen_type", 1);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("combat_exp", 800);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 20);
        set("attitude", "peaceful");
  	set("chat_chance",10);
  	set("chat_msg",({
        "�峤̾���������ĵ��������ڻ�û�������᲻����°���\n",
	"�峤��������������쵽���ֵط�ȥ������Ҫ���µġ�\n",
      	}));

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object(__DIR__"obj/hanyan");
        add_money("coin", 50);
set("inquiry", ([
"name": "�����������Ϊ�����Ҿ���������Դ��ѡ�ҵ��˴峤��\n",
"here": "�����һ�����Ҳ��\n",
"�һ���": "�����һ��������ǿ��Ǹ���ط�����˵ɽ��������������ȥ���˶����ˣ�\n",
]) );

}

