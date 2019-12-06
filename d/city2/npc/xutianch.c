// xutianch.c ���촨

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int ask_weiwang();
int do_skills(string arg);

void create()
{
	set_name("���촨", ({ "xu tianchuan", "xu", "tianchuan" }));
	set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");
	set("nickname", "�˱�Գ��");
	set("gender", "����");
	set("long", "\n������ľ����һ�����ĺ��֣����Ϲ���ʮ���˵ã�������ʹһ�׺�ȭ��\n");
	set("age", 55);

	set("int", 30);
	
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 500);
	set("max_jing", 500);
	set("shen_type", 1);

	set("combat_exp", 75000);
	set("attitude", "friendly");

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 90);
	set_skill("unarmed", 90);
	set_skill("hand", 100);
	set_skill("hunyuan-yiqi", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("houquan", 100);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 35);
	set("env/wimpy", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "houquan");
	map_skill("unarmed", "houquan");
	map_skill("parry", "houquan");

	set("chat_chance", 3);
	set("chat_msg", ({
	"���촨�����룬˵��������Ҫ�����ʹ����ҵ�������Ӳźð���\n",
	"���촨˵��: ������������Ҫ������ֵ�ߴ��кô�����\n",
        "���촨ͻȻ˵���Դ˴������ֵܣ�����������Բʱ��\n",
        "���촨ͻȻ˵���������Ž����֣��������ı����ġ�\n",
	}));

        set("inquiry", ([
		"�½���" :  "\n����ܶ����ɲ����װ���\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ�书��\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
                "ȥ�帴����" : "ȥҩ����������ϸ���ưɣ�\n",
                "ȥ�帴��" : "ȥҩ����������ϸ���ưɣ�\n",
                "���帴��" : "ȥҩ����������ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n���촨˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("���촨��˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}

int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
    }
    return 1;
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="xu" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
//		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
	write("���촨ŭ��������ػ���Ӳ��ܲ쿴������һ�٣�����Ц��:��Ȼ����ʦ���⡣\n");
		return 1;
	}

   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����ڹ� (force)                         - �����뻯  70 \n"+
"  �����Ṧ (dodge)                         - �����뻯  70 \n"+    
"  �����м� (parry)                         - һ����ʦ  90 \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90 \n"+
"  �����ַ� (hand)                          - ��ɲ� 100 \n"+
"����Ԫһ���� (hunyuan-yiqi)                - �����뻯  70 \n"+
"�������� (shaolin-shenfa)                - �����뻯  70 \n"+
"����ȭ (houquan)                           - ��ɲ� 100 \n");
return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
