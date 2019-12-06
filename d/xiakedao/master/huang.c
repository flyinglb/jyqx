#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("��ҩʦ", ({"huang-yaoshi", "huang", "yaoshi"}));
    set("title", "�һ�����");
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 100);
	
    set("combat_exp", 1500000);
    set("score", 0);
	 
    set_skill("force", 150);             // �����ڹ�
    set_skill("bibo-shengong", 150);     // �̲���
    set_skill("claw", 150);              // ����צ��
    set_skill("hand", 150);              // �����ַ�
    set_skill("finger", 170);            // ����ָ��
    set_skill("tanzhi-shentong", 170);   // ��ָ��ͨ
    set_skill("unarmed", 180);           // ����ȭ��
    set_skill("strike", 180);            // ����ȭ��
    set_skill("luoying-zhang", 180);     // ��Ӣ����
    set_skill("xuanfeng-leg", 180);      // ����ɨҶ��
    set_skill("dodge", 150);             // ��������
    set_skill("anying-fuxiang", 120);    // ��Ӱ����
    set_skill("parry", 150);             // �����м�
    set_skill("sword", 200);             // ��������
    set_skill("luoying-shenjian", 200);  // ��Ӣ��
    set_skill("yuxiao-jian", 200);       // ���｣��
    set_skill("lanhua-shou", 200);       // ������Ѩ��
    set_skill("qimen-wuxing",150);       // ��������
    set_skill("count",150);              // ��������
    set_skill("literate",150);           // ����ʶ��
	
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "luoying-zhang");
    map_skill("strike" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "luoying-shenjian");
    map_skill("sword"  , "yuxiao-jian");

    create_family("�һ���", 1, "����");
    setup();

    carry_object("/clone/misc/cloth")->wear();
    carry_object("/kungfu/class/taohua/obj/yuxiao")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say  һ�ƴ�ʦ������λһ������ȴ����Ϊɮ���˾����������������������⡣");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="yideng-dashi")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

