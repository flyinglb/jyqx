// wuchen.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�޳�����", ({"wuchen daozhang", "wuchen", "daozhang"}));
	set("title", HIR"�컨��"HIG"������"NOR);
	set("nickname", HIC "׷�������" NOR );
	set("gender", "����");
	set("age", 52);
	set("long", 
"�������޳����ˡ�����ʱ�켣���֣��ٸ���ƶ�������������ް�����
����ǿ�������ֵ����ڣ��ٸ��κ������á���һ��������һλ�ټ�С
�㣬��Ȼ�������صİ�����������λС��ȴ���޳���û���ģ����˸�
�׽�����һ��ҹ���޳�͵͵������֮ʱ����С��˵���������ȫ�Ǽ�
�⣬û�����ġ����޳���Ȼ���ķ��䡣��С��������������˰���
�����Ļ�������˵�������ô��������һ�Σ��ҿɲ�������Ҫ������
���ң��Ͱ���һ���ְ������ҡ����������۰����ţ�Ҳ����Ҽ�į
�µ������޳�һ�ﲻ������İν����Լ�����ۿ���������С��¥��
����������ٲһ����ӿ�˳������޳���ʹ���ڵأ����ﻹ�ܵ�
�����޳����µ��ֵ��Ǵ��Ⱥ�������Ƴǳأ������ȳ����ְ�С��ȫ
�Ҷ�׽�����������䡣������Ϊ�޳����ǰ����Ƕ�ɱ�ˣ�����Ҫ����
С�������ӡ���֪������С�㣬�ĳ�һ�������˰����ͼ��˶����ˣ�
�Լ���ҹ�����뿪���ǵط����Ļ��������ʹ˳������˵��ˡ�����Ȼ
���˼ң����Ǳ������ƣ����Ǻ������������������컨���ϵ���
����ͤ��������˸��֡�\n");
	set("attitude", "peaceful");
	set("class", "taoist");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);

	set("book_count", 1);
	set("combat_exp", 1000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("bibo-shengong", 200);
	set_skill("unarmed", 200);
	set_skill("xuanfeng-leg", 200);
	set_skill("dodge", 200);
	set_skill("damo-jian", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);

	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "damo-jian");
	map_skill("sword"  , "damo-jian");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanjue" :),
                (: perform_action, "unarmed.kuangfeng" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
    
}
