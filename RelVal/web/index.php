<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

include('header.html');

function has_no_dot($a) {
  return strpos($a, '.') === FALSE;
}

function list_directory($directory) {
  $directory = ltrim($directory, '/');
  if (!file_exists($directory) or strpos($directory, '..') !== FALSE)
    $directory = '.';

  $objs = array_filter(scandir($directory), 'has_no_dot');

  $meta_file = $directory . '/metadata.txt';
  if (file_exists($meta_file)) {
    echo '<div class="metadata">' . "\n";
    echo nl2br(file_get_contents($meta_file));
    echo '</div>' . "\n";

    uasort($objs, 'put_common_in_front');

    foreach ($objs as $obj) {
      $glob_check = glob($directory . '/' . $obj . '/*_FLAG.txt');
      $warn = (count($glob_check) == 0) ? '' : ' warn';
      printf('<div class="header%s" onclick=reveal("%s")>' . "\n", $warn, $obj);
      printf('<h3>%s</h3>' . "\n", $obj);
      echo '</div>' . "\n";
      printf('<div style="display:none;" class="plots" id="%s">' . "\n", $obj);
      $plots = scandir($directory . '/' . $obj);
      echo '{"plots": [';
      $nocomma = TRUE;
      foreach ($plots as $plot) {
        $file_parts = pathinfo($plot);
        if ($file_parts['extension'] == 'pdf' and substr($file_parts['filename'], -4) != '_log') {
          $base = $directory . '/' . $obj . '/' . $file_parts['filename'];
          $warn = (file_exists($base . '_FLAG.txt')) ? ' warn' : '';
          $plot_id = $obj . '/' . $file_parts['filename'];
          if ($nocomma)
            $nocomma = FALSE;
          else
            printf(', ');
          printf('{"base": "%s", "warn": "%s", "id": "%s"}', $base, $warn, $plot_id);
        }
      }
      echo "]}\n";
      echo '</div>' . "\n";
    }

  } else {

    usort($objs, function($a, $b) use ($directory) {
        return filemtime($directory . '/' . $a) < filemtime($directory . '/' . $b);
      });

    echo '<br>';
    foreach ($objs as $dir) {
      $fulldir = ltrim($directory . '/', './') . $dir;
      $metafile = $fulldir . '/metadata.txt';
      $roomy = '';
      $meta = '';
      if (file_exists($metafile)) {
        $roomy = ' roomy';
        $meta = sprintf('<a href="%s"><div class="metalink"><h3>metadata</h3></div></a><a href="%s"><div class="indexlink"><h3>index</h3></div></a>',
                        $metafile, $fulldir);
      }
      printf('<a href="?d=%s"><div class="header%s"><h3>%s</h3></div></a>' . "\n", $fulldir, $roomy, $dir);
      echo $meta . '<br>';
    }
  }
}

function put_common_in_front($a, $b) {
  if ($a == 'common')
    return -1;
  if ($b == 'common')
    return 1;
  return ($a < $b) ? -1 : 1;
}

$dirs = array_filter(scandir('.', 1), 'has_no_dot');

$directory = isset($_GET['d']) ? $_GET['d'] : '.';

list_directory($directory);

include('footer.html');

?>
