int do_ridelz()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat ��������"+ob->query("name")+
		"���"+RANK_D->query_rude(ob)+"��͵��\n");
		return 1;
	}
	switch (random(3))
	{
		case 1:
			hname=MAG"������"NOR;
			break;
		case 2:
			hname=RED"�����"NOR;
			break;
		default:
			hname=HIY"������"NOR;
			break;
	}
	message_vision(
"������ָ�$Nǣ��һƥ"+hname+"��$N����Ծ��������������������·������һ��
���: �����ޡ�\n"NOR , ob );
	message_vision("\nֻ��$N������һ�У�"+hname+"�����͵��ȥ��\n",ob);
	ob->move("/d/huanghe/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/yongdeng");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/gulang");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/dacaigou");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/wuqiao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/wuwei");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/tumenzi");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/shixiazi");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/bingcao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/yinpanshui");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/huanghe/guchangcheng");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"Ծ��ƺ��з�������԰���\n", ({ob}));
	ob->move("/d/lingzhou/xuanhebao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/mingshazhou");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/qingtongxia");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/xiaoba");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/huangyangtan");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/nanmen");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/nandajie");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/chema");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
	ob->move("/d/lingzhou/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ݡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}
