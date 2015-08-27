import "cuckoo"


rule Pony_malware
{

	meta:
			      company = "Damballa Inc"
            author = "Loucif Kharouni"
            date = "2015-06-15"
            description = "catching pony malware related to my paper"
    
    strings:
		$gate1 = ".com/gate.php"
        $gate2 = ".ru/gate.php"

	condition:
    	filesize > 100KB and
		file_type contains "pe" and $gate1 or $gate2      
        or(
              cuckoo.network.http_post(/gate\.php/)and
              cuckoo.filesystem.file_access(/C\:\\WINDOWS\\wcx_ftp\.ini/)

              )

}