//chinese.c
//modify byp@jyqxz 2000.09.12

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;

	if( !arg || arg=="" )
		return notify_fail("指令格式：chinese [<英文> to <中文>] | [-l <英文>] | [-d <英文>] \n");;
        
        if( sscanf(arg, "-l %s", key) ) {
                chinz = to_chinese(key);
                if(chinz == key)
                        write( "没有找到这个单词。\n");
                else
                        write( "单词 " + key + " == " + chinz + "\n");
                return 1;
        }
	//对于 dict 的改动也许不需要记录
	if( sscanf(arg, "%s to %s", key, chinz) == 2 ) {
		CHINESE_D->add_translate(key, chinz);
		log_file("dict_modify", sprintf("add_dict %s %s to %s %s\n", geteuid(me), key, chinz, ctime(time())) );
		write( "增加单词 " + key + " to " + chinz + "\nOk.\n");
		return 1;
	}
	if( sscanf(arg, "-d %s", key) ) {
	        chinz = to_chinese(key);
	        CHINESE_D->remove_translate(key);
	        log_file("dict_modify", sprintf("del_dict %s %s == %s %s\n", geteuid(me), key, chinz, ctime(time())) );
	        write( "删除单词  " + key + "\nOk.\n");
	        return 1;
	}
	return 0;
}

int help()
{
	write ( @HELP
指令格式：chinese [<英文> to <中文>] | [-l <英文>] | [-d <英文>] 

这个指令用来管理英文对中文的翻译。在增加翻译前请先用 -l <英文>
来列出是否有翻译或翻译是否错误。-d <英文> 是删除翻译(慎用！)。
HELP
	);
	return 1 ;
}
