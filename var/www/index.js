(() => {
  const main = document.querySelector('main');
  main.addEventListener('click', (e) => {
    if (!e.target.id) return;
    const url = '/' + e.target.id.replace(/-/g, '/');
    fetch(url, {method:'post'});
  })
})();
