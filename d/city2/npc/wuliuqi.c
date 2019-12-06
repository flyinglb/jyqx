// wuliuqi.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();

void create()
{
	set_name("������", ({"wu liuqi", "wu","liuqi"}));
	set("title", HIR"��ػ��˳��"NOR"����");
	set("nickname", "��ؤ");
	set("gender", "����");
	set("age", 50);
	set("long", 
		"����Ͻл����������������ġ���ؤ�������棬�����������\n"
		"���ڹپӹ㶫�ᶽ֮ʱ������һʡ�ر������˲���諵�Ȱ����\n"
		"�Ĵ淴�帴��֮־��������ػᣬ��ְ��˳��������\n"
	);

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	
	set("combat_exp", 150000);
	set("score", 30000);
	
	set_skill("force", 95);			// �����ڹ�
	set_skill("huntian-qigong", 90);	// ��������
	set_skill("unarmed", 90);		// ����ȭ��
	set_skill("xianglong-zhang", 85);	// ����ʮ����
	set_skill("dodge", 90);			// ��������
	set_skill("xiaoyaoyou", 95);		// ��ң��
	set_skill("parry", 85);			// �����м�
	set_skill("begging", 50);		// �л�����
	set_skill("checking", 50);		// ����;˵
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	set("chat_chance", 3);
	set("chat_msg", ({
	"�������Ȼ�ſ������������������߽��ߣ���ǻ�ߺ���˭�ԣ���������\n"
	"���������������ζ������¸����̡������Դ��У�������Զ��\n",
	"������˵: ������������Ҫ�������ߴ��кô�����\n",
        "������ͻȻ˵��: �ɰض�֦�����ң��нں黪����ͤ��\n",
        "������ͻȻ˵��: ������ǰ����Ը�����帴���Һ�Ӣ��\n",
	}));
        set("inquiry", ([
		"�½���" :  "\n����ܶ����ɲ����װ���\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ�书��\n",
                "���帴��" : "ȥҩ�̺͹ײĵ���ϸ���ưɣ�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("\n��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
		return 0;
	}
	return 1;
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="wu" )
		return 0;
	if(wizardp(ob))
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �л����� (begging)                       - �������  50/   \n"+ 
"  ����;˵ (checking)                      - �������  50/   \n"+ 
"  �����Ṧ (dodge)                         - һ����ʦ  90/   \n"+ 
"  �����ڹ� (force)                         - һ����ʦ  95/   \n"+ 
"���������� (huntian-qigong)                - һ����ʦ  90/   \n"+
"  �����м� (parry)                         - �Ƿ��켫  85/   \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90/   \n"+
"������ʮ���� (xianglong-zhang)             - �Ƿ��켫  85/   \n"+
"����ң�� (xiaoyaoyou)                      - һ����ʦ  95/   \n");
	return 1;
}
#include "/kungfu/class/yunlong/tiandihui.h";
